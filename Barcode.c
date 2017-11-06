//
// Created by parallels on 11/1/17.
//
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Barcode.h"

#define MAX_NUMBER_OF_BARCODES 64

static int decoderHandle = 0;

static int numBarcodes = 0;

BarcodeResult *barcodeResults[MAX_NUMBER_OF_BARCODES] = {NULL};

int dataLength = 0;
int symbolType = 0;
int symbolModifier = 0;
int decodeTime = 0;
int numNonDecode = 0;
int quality = 0;

char dataBuffer[DATA_BUFFER_SIZE];

CRPOINT bound[4];
CRPOINT unDecodeBound[4];
CRPOINT center;

int OnResult(int handle);
int OnStatus(int handle);
int OnProgress(int handle);

int doCortexDecode(const unsigned char *image, int imageWidth, int imageHeight,
                   CRPOINT barcodeTopLeft, int barcodeWidth, int barcodeHeight, int handle);

int getNumberOfBarcodes()
{
    return numBarcodes;
}

BarcodeResult *getBarcodeResult(int index)
{
    return barcodeResults[index];
}

int init()
{

    decoderHandle = initDecoder();

    if (decoderHandle != 1)
    {
        printf("Decoder cannot be initialized.\n");

        return -1;
    }

    return decoderHandle;

}

CRPOINT getBound(int i)
{
    return bound[i];
}

int getQuality()
{
    return quality;
}

int getDecodeTime()
{
    return decodeTime;
}

int initDecoder(void)
{
    int handle = CRD_Create();
    if (handle == 1)
    {
        CRD_Set(handle, P_CALLBACK_RESULT, (void *) OnResult);
        CRD_Set(handle, P_CALLBACK_PROGRESS, (void *) OnProgress);
        CRD_Set(handle, P_CALLBACK_STATUS, (void *) OnStatus);

        CRD_Set(handle, P_ENABLE_DM, (void*)1);

        return handle;
    }
    else if (handle == ERR_INVALID_HANDLE)
    {
        fprintf(stderr, "CDR_Create(), invalid handle - %d\n.", handle);
    }
    else if (handle == ERR_INSUFFICIENT_MEMORY)
    {
        fprintf(stderr, "CDR_Create(), insufficient memory - %d\n.", handle);
    }
    else
    {
        fprintf(stderr, "CDR_Create(), unknown error - %d\n.", handle);
    }

    return handle;
}

int OnResult(int handle)
{
    /* Get decoder results */
    CRD_Get(handle, P_RESULT_LENGTH, &dataLength);
    CRD_Get(handle, P_RESULT_STRING, &dataBuffer[0]);
    CRD_Get(handle, P_RESULT_CORNERS, &bound[0]);
    // CRD_Get(handle, P_RESULT_CENTER, &center);
    // CRD_Get(handle, P_RESULT_SYMBOL_TYPE, &symbolType);
    // CRD_Get(handle, P_RESULT_SYMBOL_MODIFIER, &symbolModifier);
    CRD_Get(handle, P_RESULT_TOTAL_TIME, &decodeTime);
    CRD_Get(handle, P_RESULT_QUALITY, &quality);

    /* For multiple barcode, do not set the following */
    CRD_Set(handle, P_STOP_DECODE, (void*) 0);

    u_int32_t minX = INT32_MAX;
    u_int32_t minY = INT32_MAX;
    u_int32_t maxX = 0;
    u_int32_t maxY = 0;

    BarcodeResult *barcodeResult = malloc(sizeof (BarcodeResult));
    for (int i = 0; i < 4; i++)
    {
        barcodeResult->corners[i].x = bound[i].x;
        barcodeResult->corners[i].y = bound[i].y;

        if (bound[i].x > maxX)
        {
            maxX = bound[i].x;
        }
        if (bound[i].x < minX)
        {
            minX = bound[i].x;
        }

        if (bound[i].y > maxY)
        {
            maxY = bound[i].y;
        }
        if (bound[i].y < minY)
        {
            minY = bound[i].y;
        }

    }

    barcodeResult->topLeft.x = minX;
    barcodeResult->topLeft.y = minY;
    barcodeResult->width = maxX - minX;
    barcodeResult->height = maxY - minY;

    barcodeResult->value = malloc(dataLength + 1);

    strncpy(barcodeResult->value, dataBuffer, dataLength);
    barcodeResult->value[dataLength] = '\0';

    barcodeResult->quality = quality;

    barcodeResult->time = decodeTime;

    if (numBarcodes < MAX_NUMBER_OF_BARCODES)
    {
        barcodeResults[numBarcodes++] = barcodeResult;
    }
    else
    {
        fprintf(stderr, "Number of barcodes exceed limit of %d...\n", MAX_NUMBER_OF_BARCODES);
    }

    return 0;

}

/* Will be called approximately every 1 millisecond */
int OnProgress(int handle)
{
    /* do something */

    return 0;
}

int OnStatus(int handle)
{
    printf("OnStatus called...\n");
    CRD_Get(handle, P_RESULT_CORNERS, &unDecodeBound[0]);
    numNonDecode++;
    return 0;
}

int decode(const unsigned char *barcodeImage, int width, int height)
{

    CRPOINT barcodeTopLeft = {0, 0};

    return decodeWithROI(barcodeImage, width, height, barcodeTopLeft, width, height);

}

int decodeWithROI(const unsigned char *barcodeImage, int width, int height,
              CRPOINT barcodeTopLeft, int barcodeWidth, int barcodeHeight)
{
    return doCortexDecode(barcodeImage, width, height, barcodeTopLeft, barcodeWidth, barcodeHeight, decoderHandle);

}

int doCortexDecode(const unsigned char *image, int imageWidth, int imageHeight, CRPOINT barcodeTopLeft, int barcodeWidth, int barcodeHeight, int handle)
{
    int xd = 0, imgBufWidth = 0;
#ifdef DUAL_FIELD
    xd = imageWidth / 2;
    imgBufWidth = xd;
#else
    xd = 0;
    imgBufWidth = imageWidth;
#endif

    /*Set image properties */
    CRD_Set(handle, P_IMAGE_ADDRESS, (void *) &image[xd]);
    CRD_Set(handle, P_IMAGE_WIDTH, (void *) imageWidth);
    CRD_Set(handle, P_IMAGE_HEIGHT, (void *) imageHeight);
    CRD_Set(handle, P_IMAGE_BUF_WIDTH, (void *) imgBufWidth);

    /* Set Region of Interest for decoding */
    CRD_Set(handle, P_BC_ROI_LEFT, (void *) barcodeTopLeft.x);
    CRD_Set(handle, P_BC_ROI_TOP, (void *) barcodeTopLeft.y);
    CRD_Set(handle, P_BC_ROI_WIDTH, (void *) barcodeWidth);
    CRD_Set(handle, P_BC_ROI_HEIGHT, (void *) barcodeHeight);

    /* Call decoder: before the function return, OnResult callback will */
    /* be called and dataLength is retrieved when a barcode is decoded. */
    dataLength = 0;

    int status = CRD_Decode(handle);

    // TODO:  Create generic error reporting function.
    if (status == ERR_INVALID_HANDLE)
    {
        fprintf(stderr, "CDR_Decode(), invalid handle - %d\n.", status);
    }
    else if (status == ERR_RESERVED_1)
    {
        fprintf(stderr, "CDR_Decode(), OEM key not found - %d\n.", status);
    }
    else if (status == ERR_NO_SYMBOLOGY_ENABLED)
    {
        fprintf(stderr, "CDR_Decode(), no symbology enabled - %d\n.", status);
    }
    else if (status == DECODE_QUIT)
    {
        fprintf(stderr, "CDR_Decode(), decoder quit - %d\n.", status);
    }

    return status;

}

void destroy()
{
    int status = CRD_Destroy(decoderHandle);

    if (status == ERR_INVALID_HANDLE)
    {
        fprintf(stderr, "CRD_Destroy(), invalid handle - %d\n.", status);
    }

    for (int i = 0; i < numBarcodes; i++)
    {

        free(barcodeResults[i]->value);
        free(barcodeResults[i]);

        barcodeResults[i] = NULL;

    }

}
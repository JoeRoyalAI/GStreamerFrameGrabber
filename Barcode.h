//
// Created by parallels on 11/1/17.
//
#include "crdDefs.h"

#ifndef GSTREAMERFRAMEGRABBER_BARCODE_H
#define GSTREAMERFRAMEGRABBER_BARCODE_H

#define DATA_BUFFER_SIZE 5000

typedef struct {

    char *value;

    int quality;

    CRPOINT corners[4];
    CRPOINT topLeft;

    int width;
    int height;


    int time;

} BarcodeResult;

int init();

int decodeROI(const unsigned char *barcodeImage, int width, int height, CRPOINT barcodeTopLeft, int barcodeWidth, int barcodeHeight);

int decode(const unsigned char *barcodeImage, int width, int height);

int getNumberOfBarcodes();

BarcodeResult *getBarcodeResult(int index);

void destroy();

#endif //GSTREAMERFRAMEGRABBER_BARCODE_H
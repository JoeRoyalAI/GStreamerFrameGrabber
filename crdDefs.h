/**************************************************************************************
*
* Code Corporation Confidential and Proprietary.
* Dissemination or reproduction of this information is forbidden.
* 2010 - 2016 Code Corporation. All Rights Reserved.
*
**************************************************************************************/
#ifndef CRD_DEFS_H
#define CRD_DEFS_H

#define CD_VERSION_MAJOR                    16
#define CD_VERSION_MINOR                    1
#define CD_VERSION_REVISION                 2
#define CD_VERSION_STRING                   "cd(16.1.2)"

/* P for Property, V for Value */

/* Properties - Image */
#define P_IMAGE_ADDRESS                     0
#define P_IMAGE_WIDTH                       1
#define P_IMAGE_HEIGHT                      2
#define P_IMAGE_BUF_WIDTH                   3
#define P_IMAGE_TYPE                        4
#define P_IMAGE_ADDRESS_EX                  5

#define P_CODE_RESERVED_1                   8
#define P_CODE_RESERVED_2                   9

/* Properties - Callback */
#define P_CALLBACK_RESULT                   10
#define P_CALLBACK_PROGRESS                 11
#define P_CALLBACK_STATUS                   12

#define P_CODE_RESERVED_3                   20
#define P_CODE_RESERVED_12                  21
#define P_CODE_RESERVED_13                  22
#define P_CODE_RESERVED_14                  23
#define P_CODE_RESERVED_15                  24
#define P_CODE_RESERVED_16                  25
#define P_CODE_RESERVED_17                  26
#define P_CODE_RESERVED_18                  27
#define P_AGC_COMPOUND_GAIN_INITIAL         28
#define P_AGC_COMPOUND_GAIN                 29
#define P_AGC_DESIRED_LIGHT                 30
#define P_CODE_RESERVED_19                  31
#define P_CODE_RESERVED_20                  32

/* Properties - Symbology Types */
#define P_ENABLE_GC                         100
#define P_ENABLE_DM                         101
#define P_ENABLE_QR_2005                    102
#define P_ENABLE_QR                         102         /* deprecated */
#define P_ENABLE_AZ                         103
#define P_ENABLE_MAXICODE                   104
#define P_ENABLE_PDF                        105
#define P_ENABLE_MICRO_PDF                  106
#define P_ENABLE_CCA                        107
#define P_ENABLE_CCB                        108
#define P_ENABLE_CCC                        109
#define P_ENABLE_C128                       110
#define P_ENABLE_C39                        111
#define P_ENABLE_C93                        112
#define P_ENABLE_I25                        113
#define P_ENABLE_CBAR                       114
#define P_ENABLE_UPCA                       115
#define P_ENABLE_UPCE                       116
#define P_ENABLE_EAN13                      117
#define P_ENABLE_EAN8                       118
#define P_ENABLE_DB_14                      119
#define P_ENABLE_DB_14_STACKED              120
#define P_ENABLE_DB_LIMITED                 121
#define P_ENABLE_DB_EXPANDED                122
#define P_ENABLE_DB_EXPANDED_STACKED        123
#define P_ENABLE_ALL_1D                     124
#define P_ENABLE_ALL_2D                     125
#define P_ENABLE_ALL                        126
#define P_ENABLE_HX                         127
#define P_ENABLE_MICRO_QR                   128
#define P_ENABLE_QR_MODEL1                  129
#define P_ENABLE_GM                         130

#define P_ENABLE_CUSTOM_NC                  131
#define P_ENABLE_CUSTOM_02                  132

#define P_ENABLE_C11                        140
#define P_ENABLE_C32                        141
#define P_ENABLE_PLE                        142
#define P_ENABLE_MSI_PLE                    143
#define P_ENABLE_TLP                        144
#define P_ENABLE_TRI                        145
#define P_ENABLE_PHA                        146
#define P_ENABLE_M25                        147
#define P_ENABLE_S25                        148
#define P_ENABLE_C49                        149
#define P_ENABLE_C16K                       150
#define P_ENABLE_CBLK                       151
#define P_ENABLE_HK25                       152
#define P_ENABLE_POSTNET                    153
#define P_ENABLE_PLANET                     154
#define P_ENABLE_INTEL_MAIL                 155
#define P_ENABLE_UPU                        156
#define P_ENABLE_AUSTRA_POST                157
#define P_ENABLE_DUTCH_POST                 158
#define P_ENABLE_JAPAN_POST                 159
#define P_ENABLE_ROYAL_MAIL                 160
#define P_ENABLE_KOREA_POST                 161
#define P_ENABLE_NEC25                      162
#define P_ENABLE_IATA25                     163
#define P_ENABLE_CANADA_POST                164
#define P_ENABLE_BC412                      165

/* Properties - Symbology Checksum Options */
#define P_CHECKSUM_C39                      200
#define P_CHECKSUM_I25                      201
#define P_CHECKSUM_CBAR                     202

/* Properties - Symbology Configuration Options */
#define P_FULL_ASCII_C39                    203
#define P_I25_LENGTH                        204
#define P_DM_RECT                           205
#define P_UPC_SUPPLEMENT                    206
#define P_UPC_E_EXPANSION                   207
#define P_POLARITY_LINEAR                   208
#define P_POLARITY_DM                       209
#define P_POLARITY_QR                       210
#define P_POLARITY_AZ                       211
#define P_POLARITY_GC                       212
#define P_POLARITY_HX                       213
#define P_POLARITY_GM                       214
#define P_POLARITY_RESERVED2                215
#define P_POLARITY_RESERVED3                216

#define P_MIRROR_DM                         217
#define P_MIRROR_QR                         218
#define P_MIRROR_AZ                         219
#define P_MIRROR_GC                         220
#define P_MIRROR_HX                         221
#define P_MIRROR_GM                         222
#define P_MIRROR_RESERVED2                  223
#define P_MIRROR_RESERVED3                  224

#define P_DM_RECT_EXTENDED                  225

/* Properties - Extended Symbology Checksum Options */
#define P_CHECKSUM_C11                      239
#define P_CHECKSUM_C25                      240
#define P_CHECKSUM_MSI_PLE                  241
#define P_STRIPCHAR_MSI_PLE                 242
#define P_PHARMA_MIN_NUM_BARS               243
#define P_PHARMA_MAX_NUM_BARS               244
#define P_PHARMA_MIN_VALUE                  245
#define P_PHARMA_MAX_VALUE                  246
#define P_PHARMA_REV_DEC                    247
#define P_PHARMA_COLOR_BARS                 248
#define P_STRIPCHAR_C11                     249

/* Properties -Symbology Output Options */
#define P_UPCA_TO_EAN13                     250
#define P_EAN8_TO_EAN13                     251
#define P_BOOKLAND_TO_ISBN                  252
#define P_BOOKLAND_TO_ISSN                  253
#define P_STRIP_NUM_SYS_UPCA                254
#define P_STRIP_NUM_SYS_UPCE                255
#define P_STRIP_CHAR_UPCA                   256
#define P_STRIP_CHAR_UPCE                   257
#define P_STRIP_CHAR_EAN13                  258
#define P_STRIP_CHAR_EAN8                   259
#define P_STRIP_STARTSTOP_CBAR              260
#define P_SEND_STARTSTOP_C39                261
#define P_SEND_STARTSTOP_TRI                262
#define P_DM_FOCUS_QUALITY                  263
#define P_SEND_AIM_SYMB_ID                  264
#define P_SEND_CBAR_ABC                     265
#define P_SEND_CBAR_CX                      266
#define P_REVERSE_TRIOPTIC                  267
#define P_SEND_ECC_CODEWORDS                268
#define P_TELEPEN_OUTPUT_ASCII              269
#define P_SEND_UPC_AIM_MODIFIER             270
#define P_BC412_REV_DEC                     271
#define P_SEND_ROYAL_MAIL_CHECK_CHAR        272
#define P_STRIP_AUSTRALIA_POST_CHECK_CHARS  273

/* Properties - Performance */
#define P_OPERATION_MODE                    300
#define P_STOP_DECODE                       301
#define P_AGC_ROI_LEFT                      302
#define P_AGC_ROI_TOP                       303
#define P_AGC_ROI_WIDTH                     304
#define P_AGC_ROI_HEIGHT                    305
#define P_BC_ROI_LEFT                       306
#define P_BC_ROI_TOP                        307
#define P_BC_ROI_WIDTH                      308
#define P_BC_ROI_HEIGHT                     309
#define P_DECODE_TIME_LIMIT                 310
#define P_SECURITY_LEVEL                    311
#define P_TIME_OUT_FACTOR                   312
#define P_DPM_TIMING_FACTOR                 312         /* deprecated */
#define P_TARGET_TOLERANCE_PERCENT          313
#define P_TARGET_LOCATION                   314         /* ((x << 16) + y) */
#define P_MULTICODE_SPEED                   315

#define P_ENSURE_ROI                        350
#define P_BASIC_ETCH_DPM                    351
#define P_BASIC_DOTS_DPM                    352
#define P_CELL_IMAGE                        353
#define P_CODE_RESERVED_4                   354
#define P_LOW_CONTRAST                      355
#define P_CODE_RESERVED_5                   356
#define P_CODE_RESERVED_6                   357
#define P_CODE_RESERVED_11                  358
#define P_DPM_DOTPEEN_DL                    359
#define P_DPM_DOTPEEN_LD                    360
#define P_DPM_LASER_CHEM_ETCH               361
#define P_DPM_DOTPEEN2_LD                   362
#define P_ZOOM_ROI                          363
#define P_ENHANCE_CONTRAST                  364
#define P_DPM_SMALL_MIRRORED                365
#define P_QUICK_DECODE                      366
#define P_NO_CR8000_SPEEDUP                 367
#define P_NATIVE_DUAL_FIELD                 368
#define P_MULTI_ALIGNED                     369
#define P_BASIC_INKJET_DPM                  370
#define P_BASIC_HANDHELD_DPM                371
#define P_HIGH_RES_SINGLE_LENS              372

#define P_VERSION_STRING_LENGTH             398
#define P_VERSION_STRING                    399

/* Properties - Results */
#define P_RESULT_CORNERS                    400
#define P_RESULT_CENTER                     401
#define P_RESULT_SYMBOL_TYPE                402
#define P_RESULT_LENGTH                     403
#define P_RESULT_STRING                     404
#define P_RESULT_SYMBOL_MODIFIER            405
#define P_RESULT_LINKAGE                    406
#define P_RESULT_QUALITY                    407
#define P_RESULT_ECC_ERROR                  408
#define P_RESULT_ECC_ERASURE                409
#define P_RESULT_DELTA_TIME                 410
#define P_RESULT_TOTAL_TIME                 411
#define P_RESULT_SYMBOL_TYPE_EX             412
#define P_RESULT_LOCATE_TIME                413
#define P_RESULT_DECODE_TIME                414
#define P_CODE_RESERVED_7                   415
#define P_CODE_RESERVED_8                   416
#define P_CODE_RESERVED_9                   417
#define P_CODE_RESERVED_10                  418
#define P_RESULT_DECODE_OUTPUT_FORMAT       419
#define P_RESULT_STATUS                     420
#define P_RESULT_NUM_CODEWORDS              421
#define P_RESULT_CODEWORDS_BEFORE_ECC       422
#define P_RESULT_CODEWORDS_AFTER_ECC        423
#define P_RESULT_NUM_CODEWORDS_BLOCKS       424
#define P_RESULT_NUM_CODEWORDS_LONG_BLOCKS  425
#define P_RESULT_NUM_DATA_CODEWORDS         426
#define P_RESULT_NUM_EC_CODEWORDS           427
#define P_RESULT_STRUC_APPEND_POSITION      428
#define P_RESULT_STRUC_APPEND_TOTAL         429
#define P_RESULT_STRUC_APPEND_PARITY        430
#define P_RESULT_MISC_PROPERTY              431
#define P_RESULT_AGC_LIGHT_LEVEL            432
#define P_RESULT_SYMBOL_HEIGHT_WIDTH        433
#define P_RESULT_SYMBOL_ROWS_COLUMNS        434

/* Properties - Optional Results (need to be enabled) */
#define P_RESULT_FOCUS_QUALITY              499

#define P_MIN_LENGTH_C39                    500
#define P_MIN_LENGTH_CBAR                   501
#define P_MIN_LENGTH_C128                   502
#define P_MIN_LENGTH_C93                    503

/* Properties - This item size (debugging only) */
#define P_THIS_SIZE                         504

/* Values of properties */
#define V_SYMB_GC                           (1 << 0)
#define V_SYMB_DM                           (1 << 1)
#define V_SYMB_QR_2005                      (1 << 2)
#define V_SYMB_AZ                           (1 << 3)
#define V_SYMB_MC                           (1 << 4)
#define V_SYMB_PDF                          (1 << 5)
#define V_SYMB_MPDF                         (1 << 6)
#define V_SYMB_CCA                          (1 << 7)
#define V_SYMB_CCB                          (1 << 8)
#define V_SYMB_CCC                          (1 << 9)
#define V_SYMB_C39                          (1 << 10)
#define V_SYMB_I25                          (1 << 11)
#define V_SYMB_CBAR                         (1 << 12)
#define V_SYMB_C128                         (1 << 13)
#define V_SYMB_C93                          (1 << 14)
#define V_SYMB_UPCA                         (1 << 15)
#define V_SYMB_UPCE                         (1 << 16)
#define V_SYMB_EAN13                        (1 << 17)
#define V_SYMB_EAN8                         (1 << 18)
#define V_SYMB_DB_14                        (1 << 19)
#define V_SYMB_DB_14_STA                    (1 << 20)
#define V_SYMB_DB_LIM                       (1 << 21)
#define V_SYMB_DB_EXP                       (1 << 22)
#define V_SYMB_DB_EXP_STA                   (1 << 23)
#define V_SYMB_HX                           (1 << 24)
#define V_SYMB_QR_MICRO                     (1 << 25)
#define V_SYMB_QR_MODEL1                    (1 << 26)
#define V_SYMB_GM                           (1 << 27)

#define V_SYMB_CUSTOM_NC                    (1 << 30)
#define V_SYMB_CUSTOM_02                    (1 << 29)

/* Deprecated */
#define V_SYMB_QR                           (1 << 2)
#define V_SYMB_MQR                          (1 << 25)

/* Values of properties of symbologyEx */
#define V_SYMB_EXTENDED                     0
#define V_SYMB_C11                          (1 << 0)
#define V_SYMB_C32                          (1 << 1)
#define V_SYMB_PLE                          (1 << 2)
#define V_SYMB_MSI_PLE                      (1 << 3)
#define V_SYMB_TLP                          (1 << 4)
#define V_SYMB_TRI                          (1 << 5)
#define V_SYMB_PHA                          (1 << 6)
#define V_SYMB_M25                          (1 << 7)
#define V_SYMB_S25                          (1 << 8)        /* Standard 2of5 with 3 Start/Stop bars */
#define V_SYMB_C49                          (1 << 9)
#define V_SYMB_C16K                         (1 << 10)
#define V_SYMB_CBLK                         (1 << 11)
#define V_SYMB_POSTNET                      (1 << 12)
#define V_SYMB_PLANET                       (1 << 13)
#define V_SYMB_INTEL_MAIL                   (1 << 14)
#define V_SYMB_AUSTRA_POST                  (1 << 15)
#define V_SYMB_DUTCH_POST                   (1 << 16)
#define V_SYMB_JAPAN_POST                   (1 << 17)
#define V_SYMB_ROYAL_MAIL                   (1 << 18)
#define V_SYMB_UPU                          (1 << 19)
#define V_SYMB_KOREA_POST                   (1 << 20)
#define V_SYMB_HK25                         (1 << 21)
#define V_SYMB_NEC25                        (1 << 22)
#define V_SYMB_IATA25                       (1 << 23)        /* Standard 2of5 with 2 Start/Stop bars */
#define V_SYMB_CANADA_POST                  (1 << 24)
#define V_SYMB_BC412                        (1 << 25)

#define V_SYMB_PRO1                         (1 << 31)

/* Values of miscellaneous results properties */
#define V_MISC_MIRROR_IMAGE                 (1 << 0)
#define V_MISC_LIGHT_ON_DARK                (1 << 1)

#define V_POLARITY_DARK_ON_LIGHT            1
#define V_POLARITY_LIGHT_ON_DARK            -1
#define V_POLARITY_EITHER                   0

/* True / False */
#define  V_FALSE                            0
#define  V_TRUE                             1

/* Parse/Format output */
#define P_FORMAT_OUTPUT_OPTION              800
#define P_FORMAT_OUTPUT_CONFIG_STRING_LEN   801
#define P_FORMAT_OUTPUT_CONFIG_STRING       802

/* Error Codes */
#define ERR_INVALID_HANDLE                  900
#define ERR_INSUFFICIENT_MEMORY             901
#define ERR_INVALID_PROPERTY                902
#define ERR_INVALID_VALUE                   903
#define ERR_RESERVED_1                      904
#define ERR_NO_SYMBOLOGY_ENABLED            905
#define ERR_MULTICODE_UNSUPPORTED           906
#define ERR_RESERVED_2                      907
#define ERR_RESERVED_3                      908

/* The decoder returns when the number of the specified barcodes are decoded, or the decoder is */
/* stopped by the caller in the progress callback, or the decoding time limit has been reached  */
#define DECODE_QUIT                         999
#define SEARCH_COMPLETED                    0

#define FORMAT_OUTPUT_CONFIG_STRING_LEN     2000     /* up to 2000 characters, this matches with the length defined in decode.c */

/* GS1 Composite linkage types */
enum LinkageType
{
    LinkageNone  =   0,
    LinkageCCAB  =   1,
    LinkageCCC   =   2,
};

enum PharmacodeSetting
{
    MinPharNumBars  =   4,
    MaxPharNumBars  =   16,
    MinPharValue    =   15,
    MaxPharValue    =   131070
};

enum PublicSectorBehavior
{
    PubSecParsing           =   0x01,   /* bit: on - parse; off - do not parse; */
    PubSecOutputFormat      =   0x02,   /* bit: on - JSON format; off - parsed output; */
    PubSecSimpleAgeVerify   =   0x08,   /* bit: on - enable Simple Age Verification; PubSecOutputFormat has no effect on this mode */
    PubSecSuccessAndRaw     =   0x10,   /* bit: on - parsed data + raw data; format: [4 chars for parsed data length][parsed data][raw data] */
    DataFormatting          =   0x100,  /* do data formatting */
    MatchString             =   0x200,  /* do match string */
    GS1Validation           =   0x300,  /* do GS1 validation */
    UDIValidation           =   0x400   /* do UDI validation */
};

enum ImageAnalysisType
{
    AgcBrightnessOnly,                  /* for decoder DPM AGC */
    AgcBrightnessQuality,               /* for decoder DPM AGC */
    RegionDetectBarcodeEdge1D,
    RegionDetectBarcodeFFT,
    RegionDetectBarcodeEdge1DFFT,
    RegionDetectCellphone,
    AgcCompoundGainInitial,             /* for decoder AGC */
    AgcCompoundGain                     /* for decoder AGC */
};

enum DecodeSecurityLevel
{
    SecurityLevel0,                 /* Default, most agressive decoding */
    SecurityLevel1,                 /* Reduced aggressiveness for poor quality 1D barcode */
    SecurityLevel2,                 /* Lowest aggressiveness to avoid misdecode of poor quality 1D barcode */
    SecurityLevel11 = 11,           /* Reduced aggressiveness for low resolution 1D barcode */
    SecurityLevel12                 /* Lowest aggressiveness to avoid misdecode of low resolution 1D barcode */
};

enum ImageType
{
    Image8BitGrayScale,             /* Default, 8-bit gray scale */
    ImageBGRA_CFLEX_B,              /* BGRA format for internel use */
    ImageBGRA_CFLEX_G,              /* BGRA format for internel use */
    ImageBGRA_Standard              /* BGRA format for internel use */
};

typedef struct CRPOINT
{
    int     x;
    int     y;
} CRPOINT;

typedef struct DECODE_RESULTS
{
    unsigned char *data;
    int     dataLength;
    int     symbolType;
    int     symbolTypeEx;
    int     symbolModifier;
    int     numEccError;
    int     numEccErasure;
    int     quality;
    int     focusQuality;
    int     linkage;
    int     status;
    int     deltaTime;
    int     totalTime;
    CRPOINT bound[4];
    CRPOINT center;
    int     strucAppendPosition;
    int     strucAppendTotal;
    int     strucAppendParity;
    int     miscProperty;
    int     heightWidth;
    int     numRowsColumns;
    int     reserved[17];
} DecodeResults;

#if defined (CORTEXDECODER_DLL)
#define _STDCALL __stdcall
#else
#define _STDCALL
#endif

typedef int (_STDCALL *CRDCB)(int);

#define DLLDEF(x)   extern x _STDCALL

#if defined (__cplusplus)
extern "C" {
#endif

/* Function Prototypes */
DLLDEF(int) CRD_Create(void);
DLLDEF(int) CRD_Decode(int handle);
DLLDEF(int) CRD_Destroy(int handle);
DLLDEF(int) CRD_Get(int handle, int property, void *value);
DLLDEF(int) CRD_Set(int handle, int property, void *value);
DLLDEF(int) CRD_InitMulti(int handle, unsigned char* pDataBuf, DecodeResults* pDecodeResults,
                int dataBufSize, int symbolBufSize);
DLLDEF(int) CRD_DecodeMulti(int handle, int *progressCount, int numSymbols);
#if defined (__cplusplus)
}
#endif

#endif

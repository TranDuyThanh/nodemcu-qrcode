#define PROGMEM
#define memcpy_P memcpy
#define __LPM(x) *x
#define pgm_read_word(x) *x

extern unsigned char strinbuf[];
extern unsigned char qrframe[];

extern unsigned char  WD, WDB;
#include "qrbits.h"

void qrencode(void);

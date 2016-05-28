#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qrencode.h"

char t_str[32];
//int main(int argc, char **argv)
int qrenc(int x, int y)
{
//    int x, y;
    int ret;

    // Change this to whatever string you need
    strcpy((char *)strinbuf,"test string");
//    strcpy((char *)strinbuf,"HTTP://PJRC.COM");
    qrencode();


    /* data */
// If PAD is defined, the code generates zeros all around the
// generated qrcode. You may not need it and I've left it
// undefined for what I am doing
//#define PAD
#ifdef PAD
    sprintf(t_str,"P1\n%d %d\n", WD + 8, WD + 8);
    Serial.print(t_str);
    for (y = 0; y < 4; y++) {
        for (x = 0; x < WD + 8; x++)
            Serial.print("0 ");
        Serial.print("\n");
    }
#else
    sprintf(t_str,"P1\n%d %d\n", WD, WD);
    Serial.print(t_str);
#endif
    for (y = 0; y < WD; y++) {
#ifdef PAD
        for (x = 0; x < 4; x++)
            Serial.print("0 ");
#endif
// This is the "meat" of the qrcode output. QRBIT(x,y) returns
// the value of the QR bit at position (x,y) in the QR image.
// It is up to you to modify this code (and the code in the
// PAD stuff as well if defined) so that it outputs where you
// need it. This code just prints the bits to the Serial
// monitor bit if you want to write them to a TFT display
// you'll have to modify all of this code accordingly
        for (x = 0; x < WD; x++) {
            sprintf(t_str,"%d ", QRBIT(x,y) );
            Serial.print(t_str);
        }
#ifdef PAD
        for (x = 0; x < 4; x++)
            Serial.print("0 ");
#endif
        Serial.println("");
    }
#ifdef PAD
    for (y = 0; y < 4; y++) {
        for (x = 0; x < WD + 8; x++)
            Serial.print("0 ");
        Serial.print("\n");
    }
#endif
    return 0;
}


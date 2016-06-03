#include "qrenc.h"

char t_str[32];

int qrenc (const char* str, void (*f)(int) ) {
    int x, y;
    strcpy((char *)strinbuf, str);
    qrencode();

    sprintf(t_str,"P1\n%d %d\n", WD, WD);
    Serial.print(t_str);

    // print PAD
    for (x = 0; x < WD + 2; x++) {
        (*f)(0);
    }
    (*f)(10);

    for (y = 0; y < WD; y++) {
        (*f)(0);

        for (x = 0; x < WD; x++) {
            (*f)(QRBIT(x,y));
        }
        (*f)(0);

        (*f)(10);
    }

    // print PAD
    for (x = 0; x < WD + 2; x++){
        (*f)(0);
    }

    return 0;
}

void printPixel(int x) {
    if (x == 1) Serial.print("1 ");
    if (x == 0) Serial.print("0 ");
    if (x == 10) Serial.println();
}

int qrencPrintln (const char* msg) {
    qrenc(msg, &printPixel);
    Serial.println();
    return 0;
}

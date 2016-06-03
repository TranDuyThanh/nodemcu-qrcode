#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qrencode.h"

int qrenc(const char* inputStr) {
    int x, y;

    initeccsize(1, strlen(inputStr));
    initframe();

    strcpy((char *)strinbuf,inputStr);
    qrencode();

    Serial.printf("P1\n%d %d\n", WD, WD);

    for (x = 0; x < WD+2; x++) Serial.print("0 ");
    Serial.println();

    for (y = 0; y < WD; y++) {
        Serial.print("0 ");
        for (x = 0; x < WD; x++) {
            Serial.printf("%d ", QRBIT(x,y));
        }
        Serial.print("0 ");

        Serial.println();
    }

    for (x = 0; x < WD+2; x++) Serial.print("0 ");

    freeframe();
    return 0;
}


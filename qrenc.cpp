#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qrencode.h"

char t_str[32];

int qrenc(const char* str) {
    int x, y;
    strcpy((char *)strinbuf, str);
    qrencode();

    sprintf(t_str,"P1\n%d %d\n", WD, WD);
    Serial.print(t_str);

    // print PAD
    for (x = 0; x < WD + 2; x++) Serial.print("0 ");
    Serial.print("\n");

    for (y = 0; y < WD; y++) {
        printf("0 "); // print PAD

        for (x = 0; x < WD; x++) {
            sprintf(t_str,"%d ", QRBIT(x,y) );
            Serial.print(t_str);
        }
        printf("0 "); // print PAD

        Serial.println("");
    }

    // print PAD
    for (x = 0; x < WD + 2; x++) Serial.print("0 ");
    Serial.print("\n");

    return 0;
}


#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qrencode.h"

int qrenc (const char*, void (*implement)(int) );
void printPixel(int);
int qrencPrintln (const char*);

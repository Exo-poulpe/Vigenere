#include <stdio.h>
#include <string.h>
#include "Vigenere.c"


int VigenereMethods(char text[],int rot);

int CharToPosition(char car);

char OldCharToNewChar(char car,int rot);

int IsInAlphabet(int value);



char PositionToChar(int pos);

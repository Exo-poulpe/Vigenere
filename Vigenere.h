#include <stdio.h>
#include <string.h>
#include "Vigenere.c"


void VigenereMethods(char text[],char pass[],char textout[]);

int CharToPosition(char car);

char OldCharToNewChar(char car,int rot);

int MakeInAlphabet(int value);



char PositionToChar(int pos);

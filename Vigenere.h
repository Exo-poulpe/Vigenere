#include <stdio.h>
#include <string.h>
#include "Vigenere.c"


void VigenereMethods(char text[],int rot,char textout[]);

int CharToPosition(char car);

char OldCharToNewChar(char car,int rot);

int IsInAlphabet(int value);



char PositionToChar(int pos);

/*
 * Author : Troller Fabian
 * Date : 2018/11/01
 * Description : Source H for use "Vigenere.c"
 * Version : 1.4.2.0
 * File : Vigenere.h
 * 
 */
#include <stdio.h>
#include <string.h>
#include "Vigenere.c"


void VigenereCryptMethods(char text[],char pass[],char textout[]);

void VigenereDecryptMethods(char text[],char pass[],char textOut[]);

void VigenereCryptFile(char filename[],char pass[],char outname[]);

void VigenereDecryptFile(char filename[],char pass[],char outname[]);

int CharToPosition(char car);

char OldCharToNewChar(char car,int rot);

int MakeInAlphabet(int value);



char PositionToChar(int pos);

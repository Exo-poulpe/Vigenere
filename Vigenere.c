/*
 * Author : Troller Fabian
 * Date : 2018.10.11
 * Description : This program can be crypt by methods vigenere
 * Version : 0.0.1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_MAX_SIZE_OUTPUT 1000

static char Alphabet[] = {'a','b','c','d','e','f','g','h','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

static int CharPos = 0;
static char Output[DEFAULT_MAX_SIZE_OUTPUT];

int VigenereMethods(char text[],int rot)
{
    for(int i=0; i<sizeof(text); i++)
        {
            Output[i] = OldCharToNewChar(text[i],rot);
        }
    return Output;
}

int CharToPosition(char car)
{
    for(int i=0; i < sizeof(Alphabet); i++)
        {
            if(car == Alphabet[i])
                {
                    return i;
                }
        }
}


char OldCharToNewChar(char car,int rot)
{
    CharPos = CharToPosition(car);
    CharPos = IsInAlphabet(CharPos+rot);
    return Alphabet[CharPos];
}

int IsInAlphabet(int value)
{
    if(value > strlen(Alphabet))
        {
            value -= sizeof(Alphabet);
        }
    else if(value < 0)
        {
            value += sizeof(Alphabet);
        }

    return value;
}

char PositionToChar(int pos)
{
    if(pos > strlen(Alphabet))
        {
            pos = pos - strlen(Alphabet);
        }
    return Alphabet[pos];
}




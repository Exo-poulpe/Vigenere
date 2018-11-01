/*
 * Author : Troller Fabian
 * Date : 2018/11/01
 * Description : Source C for crypt with vigenere
 * Version : 1.4.2.0
 * File : Vigenere.c
 * 
 */

#include <stdio.h>
#include <string.h>

#define DEFAULT_MAX_SIZE_OUTPUT 255
#define DEFAULT_MAX_SIZE_INPUT 255

static char Alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

static char SpecialChar[] = { " .,-£äöü!=)(/&%ç*\"+?{}]["};

static int CharPos = 0;
static char OutPut[DEFAULT_MAX_SIZE_OUTPUT];

char OldCharToNewChar(char car,int rot);

int MakeInAlphabet(int value);

int CharIsInAlphabet(char c);

char PositionToChar(int pos);

int CharToPosition(char car);






char OldCharToNewChar(char car,int rot)
{
    CharPos = CharToPosition(car);
    CharPos = MakeInAlphabet(CharPos+rot);
    car = Alphabet[CharPos];
    return car;
}

char NewCharToOldChar(char car,int rot)
{
    CharPos = CharToPosition(car);
    CharPos = MakeInAlphabet(CharPos-rot);
    car = Alphabet[CharPos];
    return car;
}


void VigenereCryptMethods(char text[],char pass[],char textOut[])
{
    for(int i=0,j=0; i<strlen(text); i++,j++)
        {
            if(CharIsInAlphabet(text[i])==1)
                {
                    if(j>strlen(pass)-1)
                        {
                            j=0;
                        }
                    if(strchr(SpecialChar,text[i]) == NULL)
                        {
                            textOut[i] = OldCharToNewChar(text[i],CharToPosition(pass[j]));
                        }
                    else
                        {
                            textOut[i] = text[i];
                            j--;
                        }
                }
            else
                {
                    textOut[i] = text[i];
                    j--;
                }
        }

}





void VigenereDecryptMethods(char text[],char pass[],char textOut[])
{
    for(int i=0,j=0; i<strlen(text); i++,j++)
        {
            if(CharIsInAlphabet(text[i])==1)
                {
                    if(j>strlen(pass)-1)
                        {
                            j=0;
                        }

                    if(strchr(SpecialChar,text[i]) == NULL)
                        {
                            textOut[i] = NewCharToOldChar(text[i],CharToPosition(pass[j]));
                        }
                    else
                        {
                            textOut[i] = text[i];
                            j--;
                        }
                }
            else
                {
                    textOut[i] = text[i];
                    j--;
                }
        }
}

void VigenereCryptFile(char filename[],char pass[],char outname[])
{
    FILE *f,*outf;
    static char txt[DEFAULT_MAX_SIZE_INPUT];
    static char tmp[DEFAULT_MAX_SIZE_OUTPUT];
    f = fopen(filename,"r");
    outf = fopen(outname,"w+");
    while (fgets(txt,DEFAULT_MAX_SIZE_INPUT,(FILE*)f))
        {
            VigenereCryptMethods(txt,pass,tmp);
            fputs(tmp,outf);
            memset(txt,0,DEFAULT_MAX_SIZE_INPUT);
            memset(tmp,0,DEFAULT_MAX_SIZE_OUTPUT);
        }
    fclose(f);
    fclose(outf);

}

void VigenereDecryptFile(char filename[],char pass[],char outname[])
{
    FILE *f,*outf;
    static char txt[DEFAULT_MAX_SIZE_INPUT];
    static char tmp[DEFAULT_MAX_SIZE_OUTPUT];
    f = fopen(filename,"r");
    outf = fopen(outname,"w+");
    while (fgets(txt,DEFAULT_MAX_SIZE_INPUT,(FILE*)f))
        {
            VigenereDecryptMethods(txt,pass,tmp);
            fputs(tmp,outf);
            memset(txt,0,DEFAULT_MAX_SIZE_INPUT);
            memset(tmp,0,DEFAULT_MAX_SIZE_OUTPUT);
        }
    fclose(f);
    fclose(outf);

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

int CharIsInAlphabet(char c)
{
    int res = 0;
    for(int i=0; i<strlen(Alphabet); i++)
        {
            if(c==Alphabet[i])
                {
                    res=1;
                }
        }
    return res;
}

int MakeInAlphabet(int value)
{
    while(value < 0)
        {
            value += strlen(Alphabet);
        }
    while(value >= strlen(Alphabet))
        {
            value -= strlen(Alphabet);
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

/*
 * Author : Troller Fabian
 * Date : 2018.10.11
 * Description : This program can be crypt by methods vigenere
 * Version : 0.1.5.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_MAX_SIZE_OUTPUT 100
#define DEFAULT_MAX_SIZE_INPUT 100

static char Alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

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
                    if(text[i]!= ' ')
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
                    if(text[i]!= ' ')
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
                }
        }
}

void VigenereCryptFile(char filename[],char pass[],char outname[])
{
	FILE *f,*outf;
	static char txt[255];
	static char tmp[255];
	f = fopen(filename,"r");
	outf = fopen(outname,"w+");
	while (fgets(txt,255,(FILE*)f))
	{
		VigenereCryptMethods(txt,pass,tmp);
		fputs(tmp,outf);
	}
	fclose(f);
	fclose(outf);

}

void VigenereDecryptFile(char filename[],char pass[],char outname[])
{
	FILE *f,*outf;
	static char txt[255];
	static char tmp[255];
	f = fopen(filename,"r");
	outf = fopen(outname,"w+");
	while (fgets(txt,255,(FILE*)f))
	{
		VigenereDecryptMethods(txt,pass,tmp);
		fputs(tmp,outf);
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
    if(value < 0)
        {
            value += sizeof(Alphabet);
        }
    if(value > strlen(Alphabet))
        {
            value -= sizeof(Alphabet);
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

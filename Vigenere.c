/*
 * Author : Troller Fabian
 * Date : 2018.10.11
 * Description : This program can be crypt by methods vigenere
 * Version : 0.0.1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char Alphabet[] = {'a','b','c','d','e','f','g','h','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

char VigenereMethods ()
{
	
    
    printf("%s",Alphabet);
    return 0;
}

int CharToPosition(char car,int rot)
{
	for(int i=0;i<strlen(Alphabet);i++)
	{
		if(car == Alphabet[i])
		{
			return i;
		}
	}
}

char PositionToChar(int ros)
{
	if(pos > strlen(Alphabet))
	{
		pos = pos - strlen(Alphabet);
	}
}



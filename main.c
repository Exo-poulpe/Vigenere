#include <stdio.h>
#include <stdlib.h>
#include "Vigenere.h"

int main()
{
    static int val;
    static char txt[100],Out[100];

    printf("Entrer votre Text : \n ");
    scanf("%s",&txt);
    printf("Entrer votre rotation : ");
    scanf("%i",&val);
    VigenereMethods(txt,val,Out);
    //Out[0] = OldCharToNewChar(txt[0],val);
    printf("Out : %s\n",Out);
    return 0;
}



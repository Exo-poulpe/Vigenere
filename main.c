#include <stdio.h>
#include <stdlib.h>
#include "Vigenere.h"

int main()
{
    static char pass[50];
    static char txt[100],Out[100];

    printf("Entrer votre Text : \n");
    fgets(txt,sizeof(txt),stdin);
    printf("Entrer votre password : ");
    scanf("%s",&pass);
    VigenereMethods(txt,pass,Out);
    //Out[0] = OldCharToNewChar(txt[0],val);
    printf("In  : %s.\n",txt);
    printf("Out : %s\n",Out);
    return 0;
}



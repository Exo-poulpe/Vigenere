#include <stdio.h>
#include "Vigenere.h"

int main()
{
    static char pass[50];
    static char txt[100],out[100];

    printf("Entrer votre Text : \n");
    fgets(txt,sizeof(txt),stdin);
    printf("Entrer votre password : ");
    scanf("%s",&pass);
    //VigenereCryptMethods(txt,pass,out);
    //Out[0] = OldCharToNewChar(txt[0],val);
    
    //printf("In  : %s\n",txt);
    //printf("Out : %s\n",out);
    VigenereDecryptMethods(txt,pass,out); 
    printf("In  : %s\n",txt);
    printf("Out : %s\n",out);
    return 0;
}



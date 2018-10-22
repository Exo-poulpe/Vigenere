#include <stdio.h>
#include <unistd.h>
#include "Vigenere.h"



static char pass[50];
static char txt[100],out[100];
static char opt[1];


void CryptMethods();

void DecryptMethods();

int main(int argc,char *argv[])
{
    printf("Choice option :\nc = Crypt\nd = Decrypt\n");
    scanf("%s",&opt);


    while (*opt!='Q')
        {
            if(*opt == 'c')
                {
                    CryptMethods();
                }
            else if(*opt == 'd')
                {
                    DecryptMethods();
                }
            else if(*opt == 'Q')
                {
                    printf("%s/\n",opt);
                    printf("Only '-c' and '-d' methods for the moments\n");
                }
            printf("Choice option :\nc = Crypt\nd = Decrypt\n");
            scanf("%s",&opt);


        }
    return 0;
}


void CryptMethods()
{
    printf("Entrer votre Text : \n");
    //fgets(txt,sizeof(txt),stdin);
    scanf("%s",&txt);
    printf("Entrer votre password : ");
    scanf("%s",&pass);
    VigenereCryptMethods(txt,pass,out);
    printf("Result : \n============\n%s\n============\n",out);

}


void DecryptMethods()
{
    printf("Entrer votre Text : \n");
    //fgets(txt,sizeof(txt),stdin);
    scanf("%s",&txt);
    printf("Entrer votre password : ");
    scanf("%s",&pass);
    VigenereDecryptMethods(txt,pass,out);
    printf("Result : \n============\n%s\n============\n",out);

}

#include <stdio.h>
#include <unistd.h>
#include "Vigenere.h"

static char pass[50];
static char txt[100],out[100];
static int opt=0;


void CryptMethods();

void DecryptMethods();

int main(int argc,char *argv[])
{
    while((opt = getopt(argc,argv,"cd")) != -1)
        {

            switch(opt)
                {
                case 'c':
                    CryptMethods();
                    break;
                case 'd':
                    DecryptMethods();
                    break;

                }
            /*
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
                  */
        }
    return 0;
}


void CryptMethods()
{
    printf("Entrer votre Text : \n");
    fgets(txt,sizeof(txt),stdin);
    printf("Entrer votre password : ");
    scanf("%s",&pass);
    VigenereCryptMethods(txt,pass,out);
    printf("Result : \n %s",out);

}
void DecryptMethods()
{
    printf("Entrer votre Text : \n");
    fgets(txt,sizeof(txt),stdin);
    printf("Entrer votre password : ");
    scanf("%s",&pass);
    VigenereDecryptMethods(txt,pass,out);
    printf("Result : \n%s",out);

}

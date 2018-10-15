#include <stdio.h>
#include <unistd.h>
#include "Vigenere.h"

static char pass[50];
static char txt[100],out[100];
static char opt[2];


void CryptMethods();

void DecryptMethods();

int main(int argc,char *argv[])
{
	printf("Choice option :\nc = Crypt\nd = Decrypt\n");
	scanf("%s",&opt);

           if(opt == "-c")
	   {
		CryptMethods();
	   } 
	   else if(opt == "-d")
	   {
		DecryptMethods();
	   }
           else
	   {

	printf("%s\n",opt);
	      printf("Only '-c' and '-d' methods for the moments\n");
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

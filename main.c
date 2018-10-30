#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "Vigenere.h"



static char pass[50];
static char txt[100],out[100];


void CryptMethods();

void DecryptMethods();

int main(int argc,char *argv[])
{
	//extern char *optarg;
static int password = 0;
static int flag = 0;
static int opt;
enum { WORD_MODE, LINE_MODE } op_mode = WORD_MODE;


    while ((opt = getopt(argc, argv, "c:d:p:h")) != -1) {
        switch (opt)
       	{
	case 'p':strcpy(pass,optarg); password=1; break;
        case 'c':strcpy(txt,optarg); flag=1; break;
        case 'd':strcpy(txt,optarg); flag=2; break;
	case 'h': GetHelp(argv[0]); break;
        default:
		GetHelp(argv[0]);
            exit(EXIT_FAILURE);
        }

	if(flag==1 && password==1)
	{
		//printf("pass = %s   Word = %s",pass,txt);
		VigenereCryptMethods(txt,pass,out);	
		printf("\n%s\n",out);
	}
	else if(flag == 2 && password == 1)
	{
		VigenereDecryptMethods(txt,pass,out);	
		printf("\n%s\n",out);
	}

    }
	if(argc < 2)
	{
		GetHelp(argv[0]);
	}

    return 0;
}


void GetHelp(char fileName[])
{
fprintf(stderr, "Usage: %s [-cdh] \n\t-c : crypt with vigenere\n\t-d : decrypt vigenere\n\t-p : password for crypt or decrypt\n\t-h : show help\n", fileName);
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

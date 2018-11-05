/*
 * Author : Troller Fabian
 * Date : 2018/11/01
 * Description : Program use for crypted with vigenere methods file or texte
 * Version : 1.4.2.0
 * File : main.c
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "Vigenere.h"

#define DEFAULT_TEXT_SIZE 255
#define DEFAULT_PASSWORD_SIZE 50



static char VERSION[] = "1.4.2.0";
static char pass[DEFAULT_PASSWORD_SIZE];
static char txt[DEFAULT_TEXT_SIZE],out[DEFAULT_TEXT_SIZE];


void CryptMethods();

void DecryptMethods();

int main(int argc,char *argv[])
{
    static int password = 0;
    static char filename[DEFAULT_TEXT_SIZE];
    static char outfilename[DEFAULT_TEXT_SIZE];
    static int flag = 0;
    static int fflag = 0;
    static int opt;


    while ((opt = getopt(argc, argv, "p:fo:c:d:hv")) != -1)
        {
            switch (opt)
                {
                case 'p':
                    strcpy(pass,optarg);
                    password=1;
                    break;
                case 'c':
                    strcpy(txt,optarg);
                    flag=1;
                    break;
                case 'd':
                    strcpy(txt,optarg);
                    flag=2;
                    break;
                case 'h':
                    GetHelp(argv[0]);
                    break;
                case 'f':
                    fflag = 1;
                    break;
                case 'o':
                    fflag += 1;
                    strcpy(outfilename,optarg);
                    break;
		case 'v':
		    GetVersion();
		    break;
                default:
                    GetHelp(argv[0]);
                    return -1;
                }

            if(flag==1 && password==1 && fflag==2)
                {
                    VigenereCryptFile(txt,pass,outfilename);
                    printf("File %s crypted\n",outfilename);
                }
            else if(flag==2 && password==1 && fflag==2)
                {
                    VigenereDecryptFile(txt,pass,outfilename);
                    printf("File %s decrypted\n",outfilename);
                }
            else if(flag==1 && password==1)
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
    fprintf(stderr, "Usage: %s [options] [-cdpfoh] \n",fileName);
    puts("\t-c : crypt with vigenere (if -f is activate the -c get the filename to crypt)");
    puts("\t-d : decrypt vigenere (if -f is activate the -d get the filename to decrypt)");
    puts("\t-p : password for crypt or decrypt");
    puts("\t-f : file to crypt or decrypt with this options the options (-c or -d get the filename)");
    puts("\t-o : file output name");
    puts("\t-v : show version");
    puts("\t-h : show this help");
    printf("\nExemple:\n %s -f -o fileCrypted -p password -c fileToCrypt\n\n",fileName);
}


void GetVersion()
{
	puts("Author : Troller Fabian");
	printf("Version : %s\n",VERSION);
}

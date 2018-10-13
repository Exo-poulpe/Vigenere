#include <stdio.h>
#include <stdlib.h>
#include "Vigenere.h"

int main()
{
    static int val;
    static char car,Out;

    printf("Entrer votre char : ");
    scanf("%c",&car);
    printf("Entrer votre rotation : ");
    scanf("%i",&val);
    Out = OldCharToNewChar(car,val);
    printf("Out : %c\n",Out);
    return 0;
}



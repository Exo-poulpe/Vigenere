#include <stdio.h>
#include <stdlib.h>
#include "Vigenere.h"

int main()
{
    static int val;
    static char car;

    printf("Entrer votre char : ");
    scanf("%c",&car);
    printf("Entrer votre rotation : ");
    scanf("%i",&val);
    printf("%c\n",OldCharToNewChar(car,val));
    return 0;
}



#include <stdio.h>
int main(void)
{
    int guess = 1;

    printf("Pick an integer from 1 to 100. I will try guess ");
    printf("it. \nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    char respond;
    while((respond = getchar()) != 'y'){
        if(respond == 'n')
            printf("Well, then, is it %d ?\n", ++guess);
        else
            printf("Sory, I understand only y or n.\n");
        
            while(getchar() != '\n')
            continue;
    }
    printf("I knew I could do it!\n");

    return 0;
}
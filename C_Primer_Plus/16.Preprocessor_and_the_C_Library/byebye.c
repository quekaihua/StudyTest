#include <stdio.h>
#include <stdlib.h>
void sign_off(void);
void too_bad(void);

int main(void)
{
    int n;
    atexit(sign_off);

    puts("Enter an integer: ");
    if(scanf("%d", &n) != 1){
        puts("Input Error.");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n", n, (n%2) ? "odd" : "even");
    return 0;
}

void sign_off(void){puts("sign_off");}
void too_bad(void){puts("too_bad");}
#include <stdio.h>
void trystat(void);

int main(){
    int count;
    for(count = 1; count <= 3; count++){
        printf("Here comes iteration %d:\n", count);
        trystat();
    }
    return 0;
}

void trystat(void)
{
    int fade = 1;
    static int stay = 1;
    printf("fade at %p and stay at %p\n", &fade, &stay);
    printf("fade = %d and stay = %d\n", fade++, stay++);
}

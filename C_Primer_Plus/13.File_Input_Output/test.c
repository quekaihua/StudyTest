#include <stdio.h>

int main(void){
    int i = 40000, j = 50000;
    float x = 1.2, y = -1.2, z = 3.14;
    printf("x+y+z = %.6f\n", x+y+z);
    printf("x+(y+z) = %.6f\n", x+(y+z)); 
    printf("i*i = %d\n", i*i);
    printf("j*j = %d\n", j*j);

    return 0;
}

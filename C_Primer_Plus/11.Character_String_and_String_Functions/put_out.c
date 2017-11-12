#include <stdio.h>
#define DEF "I am a #define string."
int main(void)
{
    char str1[80] = "An array war initialized to me.";
    const char * str2 = "A pointer war initialized to me.";

    puts("I'm argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);
    puts(str2 + 4);
    printf("DEF: %p\n", DEF);
    printf("STRING: %p\n", "I am a #define string.");

    return 0;
}
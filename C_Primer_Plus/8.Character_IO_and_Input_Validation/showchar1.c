#include <stdio.h>
void display(char ch, int lines, int width);

int main(void)
{
    int ch;
    int rows, cols;
    printf("Enter a charater and two integers:\n");
    while((ch = getchar()) != '\n'){
        scanf("%d %d", &rows, &cols);
        display(ch, rows, cols);
        while(getchar() != '\n')
            continue;
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}

void display(char ch, int lines, int width)
{
    for(int i=0; i<lines; i++){
        for(int j=0; j<width; j++)
            putchar(ch);
        putchar('\n');
    }
}
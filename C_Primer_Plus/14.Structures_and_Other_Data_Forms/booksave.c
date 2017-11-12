#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * s_gets(char * st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);

    if((pbooks = fopen("book.dat", "a+b"))==NULL){
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1){
        if(count == 0){
            puts("Current contents of book.dat:");
        }
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if(count == MAXBKS){
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    puts("Please add the book titles.\n");
    puts("Press [enter] at the start of a line to stop.\n");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL 
        && library[count].title[0] != '\0'){
            puts("Now enter the author.\n");
            s_gets(library[count].author, MAXAUTL);
            puts("Now enter the value.\n");
            scanf("%f", &library[count++].value);
            while(getchar() != '\n')
                continue;
            if(count < MAXBKS)
                printf("Enter the next title.\n");
    }

    if(count > 0){
        puts("Here is the list of your books:\n");
        for(index = 0; index < count; index++){
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
            fwrite(&library[filecount], size, count - filecount, pbooks);
        }   
    }else
        puts("No books? Too bad.\n");
        puts("Bye.\n");
        fclose(pbooks);
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
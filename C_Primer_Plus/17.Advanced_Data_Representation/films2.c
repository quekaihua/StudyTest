#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film * next;
};

char * s_gets(char * st, int n);

int main(void){
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

    printf("Please enter the movie title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while(s_gets(input, TSIZE) != NULL && input[0] != '\0'){
        current = (struct film *) malloc(sizeof(struct film));
        if(head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        printf("Enter your rating <0-10>:\n");
        scanf("%d", &current->rating);
        while(getchar() != '\n')
            continue;
        printf("Please enter the next movie title.\n");
        prev = current;
    }

    if(head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while(current != NULL){
        printf("Movie: %s Rating: %d\n",current->title, current->rating);
        current = current->next;
    }
    
    current = head;
    while(current != NULL)
    {
        free(current);
        current = current->next;
    }
    puts("Bye!");
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
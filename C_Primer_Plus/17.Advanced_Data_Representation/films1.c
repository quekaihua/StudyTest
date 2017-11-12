#include <stdio.h>
#include <string.h>
#define TSIZE 45
#define FMAX 5

struct film{
    char title[TSIZE];
    int rating;
};

char * s_gets(char * st, int n);

int main(void){
    struct film movies[FMAX];
    int i = 0;
    int j;
    printf("Please enter the movie title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while(i < FMAX && s_gets(movies[i].title, TSIZE) != NULL 
        && movies[i].title[0] != '\0'){
            printf("Enter your rating <0-10>:\n");
            scanf("%d", &movies[i++].rating);
            while(getchar() != '\n')
                continue;
        printf("Please enter the next movie title.\n");
    }

    if(i == 0)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");

    for(j = 0; j < i; j++)
        printf("Movie: %s Rating: %d\n", movies[j].title, movies[j].rating);
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
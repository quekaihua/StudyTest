#include <stdio.h>
#include <string.h>

#define NLEN 30
struct namect{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct namect getinfo();
int makeinfo(struct namect person);
void showinfo(const struct namect person);
char * s_gets(char * st, int n);

int main(void){

    struct namect person;
    person = getinfo();
    person.letters = makeinfo(person);
    showinfo(person);
    return 0;
}

struct namect getinfo()
{
    struct namect person;
    printf("Please enter your first name.\n");
    s_gets(person.fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(person.lname, NLEN);
    return person;
}
int makeinfo(struct namect person)
{
    return strlen(person.fname) + strlen(person.lname);
}

void showinfo(const struct namect person)
{
    printf("%s %s, your name contains %d letters.\n", person.fname, person.lname, person.letters);
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
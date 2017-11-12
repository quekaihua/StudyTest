#include <stdio.h>
#define FUNDLEN 50

struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds *);

int main(void){
    struct funds stan = {
        "Garlic-Melon Bank",
        344,
        "Luckys Savings and Loan",
        123.3
    };

    printf("Stan has total of %.2f.\n", sum(&stan));
    return 0;
}

double sum(const struct funds * money){return money->bankfund + money->savefund;}
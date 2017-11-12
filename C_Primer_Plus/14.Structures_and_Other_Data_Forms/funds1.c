#include <stdio.h>
#define FUNDLEN 50

struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(double, double);

int main(void){
    struct funds stan = {
        "Garlic-Melon Bank",
        344,
        "Luckys Savings and Loan",
        123.3
    };

    printf("Stan has total of %.2f.\n", sum(stan.bankfund, stan.savefund));
    return 0;
}

double sum(double x, double y){return x+y;}
#include <stdio.h>
#define FUNDLEN 50

struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(struct funds moolah);

int main(void){
    struct funds stan = {
        "Garlic-Melon Bank",
        344,
        "Luckys Savings and Loan",
        123.3
    };

    printf("Stan has total of %.2f.\n", sum(stan));
    return 0;
}

double sum(const struct funds moolah){return moolah.bankfund + moolah.savefund;}
#include <stdio.h>
#include <stdarg.h>
double sum(int, ...);

int main(void)
{
    double s, t;
    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1 , 4.1, 5.1, 6.1);
    printf("result value for "
    "sum(s): %g", s);
    printf("result value for t: %g", t);

    return 0;
}

double sum(int lim, ...)
{
    va_list ap;
    double dot = 0;
    int i;
    va_start(ap, lim);
    for(i = 0; i < lim; i++){
        dot += va_arg(ap, double);
    }
    va_end(ap);
    return dot;
}
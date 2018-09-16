#include <bits/stdc++.h>
#define cbrt(x) pow(x, 1.0/3)
#define frrt(x) pow(x, 1.0/4)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIRST_TAX(x) (min(x, sqrt(x) + max(0.0, log(x))))
#define SECOND_TAX(x) ((2 * cbrt(x)) + (x/10))
#define THIRD_TAX(x) (max(0, log(x * ((x*x) + 5000))) + (x/2))
#define FOURTH_TAX(x) ((x / 7) + frrt(x))
#define TAXED(x) (x - get_tax(x))

typedef double F;

double get_tax(double income)
{
    F x;

    if(income <= 1e4) {
        return 0.0;
    }

    if(income <= 1e5) {
        x = max(min(income - 1e4, 1e5 - 1e4), 0.0);
        return min(x, sqrt(x) + max(0.0, log(x)));
    }

    // Te dokładne stałe wartości poniżej to policzony już wcześniej podatek dla dolnego limitu progu.

    if(income <= 1e6) {
        x = max(min(income - 1e5, 1e6 - 1e5), 0.0);
        return 311.40756494931241604718 + 2.0 * pow(x, 1.0/3.0) + x / 10.0;
    }

    if(income <= 1e7) {
        x = max(min(income - 1e6, 1e7 - 1e6), 0.0);
        return 90504.50544187043851707131 + max(0.0, log(x * (x * x + 5000.0))) + x / 2.0;
    }

    x = max(income - 1e7, 0.0);
    return 4590552.54364727623760700226 + x / 7.0 + pow(x, 1.0 / 4.0);
}

int main()
{
    uint32_t icount;
    scanf("%u", &icount);
    for(uint32_t i = 0; i < icount; i++)
    {
        double target;
        scanf("%lf", &target);
        double f = 4;
        double guess = target + (target / 2), taxed;
        for(uint32_t _i = 0; _i < 50; _i++)
        {
            taxed = TAXED(guess);
            if(target == taxed)
                break;
            else if(target < taxed)
                guess -= guess / f;
            else
                guess += guess / f;
            f *= 2.0;
        }
        printf("%.15f\n", guess);
    }
}

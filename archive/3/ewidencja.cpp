#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef double F;

int main()
{
    I n;
    scanf("%i", &n);

    I max_dzieci = -1;
    char max_dzieci_plec = 'm';
    F sum_zarobki;

    for(I i = 0; i < n; ++i) {
        char imie[30], nazwisko[40];
        F zarobki;
        char km;
        I liczba_dzieci;
        scanf("%s %s %lf %c %i", imie, nazwisko, &zarobki, &km, &liczba_dzieci);

        sum_zarobki += zarobki;

        if(liczba_dzieci > max_dzieci) {
            max_dzieci = liczba_dzieci;
            max_dzieci_plec = km;
        }
    }

    printf("Srednia wielkosc zarobkow wynosi %.3f\n", sum_zarobki / F(n));
    printf("Najwieksza liczba dzieci to %i\n", max_dzieci);
    printf("Najwieksza liczbe dzieci ma %c\n", max_dzieci_plec);

    return 0;
}

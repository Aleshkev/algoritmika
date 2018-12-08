#include <bits/stdc++.h>

using namespace std;

typedef double F;
typedef long int I;

F taxate(F income) {  // Oblicza podatek od danej kwoty.
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
    I n;
    scanf("%li", &n);

    for(I i = 0; i < n; ++i) {
        F needed_brutto;

        scanf("%lf", &needed_brutto);

        F lo = 0.0, hi = 1e9;
        while(abs(hi - lo) > 1e-6) {  // (dopóki nie osiągnięta została odpowiednia precyzja)
            F mid = (lo + hi) / 2.0;
            F this_brutto = mid - taxate(mid);
            if(this_brutto < needed_brutto) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        // Nie rozumiem, czemu tu działa tylko f, ale ważne, że działa.
        printf("%.6f\n", hi);
    }

    return 0;
}

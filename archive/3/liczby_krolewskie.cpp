#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n;
    scanf("%i", &n);

    for(I i = 0; i < n; ++i) {
        I x;
        scanf("%i", &x);

        I r = 2 * x - 1;
        if(__builtin_popcount(r) % 2 != 0) {
            --r;
        }

        printf("%i\n", r);
    }

    return 0;
}

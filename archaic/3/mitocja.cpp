#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n, m;
    scanf("%i %i", &n, &m);

    static I t[1000000];
    fill(t, t + n, 0);

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        --a; --b;
        ++t[a]; ++t[b];
    }

    printf("%i\n", count(t, t + n, 0) + count(t, t + n, 1));

    return 0;
}

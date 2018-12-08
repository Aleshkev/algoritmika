#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    static I t[1000000];

    static char s[1000000];
    scanf("%s", s);
    I n = strlen(s);
    for(I i = 0; i < n; ++i) {
        t[i] = (s[i] == 'a' ? 1 : 0);
    }

    static I u[1000000];
    partial_sum(t, t + n, u);

    I m;
    scanf("%i", &m);

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        --a; --a; --b;

        printf("%i\n", (a >= 0 ? u[b] - u[a] : u[b]));
    }

    return 0;
}

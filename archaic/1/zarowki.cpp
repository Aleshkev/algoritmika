#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    static char t[200002];
    I n;
    scanf("%i %s", &n, t + 1);

    static char u[256];
    u['0'] = '1';
    u['1'] = '0';

    I c = 0;
    for(I i = 1; i <= n; ++i) {
        if(t[i] == '0') continue;

        ++c;

        for(I j = i; j <= n; j += i) {
            t[j] = u[t[j]];
        }
    }

    printf("%i\n", c);

    return 0;
}

#include <cstdio>

using namespace std;

typedef long long int I;

I rudbeckias[1000010], unorder[1000010];

int main()
{
    I n;
    scanf("%lli", &n);

    char plant;
    scanf(" %c", &plant);
    rudbeckias[0] = (plant == 'R');
    unorder[0] = 0;
    for(I i = 1; i < n; ++i) {
        scanf(" %c", &plant);
        if(plant == 'R') {
            rudbeckias[i] = rudbeckias[i - 1] + 1;
            unorder[i] = unorder[i - 1];
        } else {
            rudbeckias[i] = rudbeckias[i - 1];
            unorder[i] = unorder[i - 1] + rudbeckias[i - 1];
        }
    }

    I m;
    scanf("%lli", &m);

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%lli %lli", &a, &b);
        --a; --b;

        I c = unorder[b];
        if(a > 0) {
            c = c - unorder[a - 1] - rudbeckias[a - 1] * (b - a + 1 - rudbeckias[b] + rudbeckias[a - 1]);
        }

        printf("%lli\n", c);
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I m;
    scanf("%li", &m);

    for(I i = 0; i < m; ++i) {
        I n, d;
        scanf("%li %li", &n, &d);

        printf("%li\n", n / __gcd(n, d));
    }

    return 0;
}

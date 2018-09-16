#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    scanf("%lli", &n);

    static I a[1000000 + 10];
    for(I i = 0; i < n; ++i) {
        scanf("%lli", &a[i]);
    }

    static I w[1000000 + 10];
    w[0] = 0;
    w[1] = a[0];
    for(I i = 2; i <= n; ++i) {
        w[i] = max(w[i - 1], w[i - 2] + a[i - 1]);
    }

    printf("%lli\n", *max_element(w, w + n + 1));

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef int I;

I t[100000];
I n;

I lower_b(I x) {
    I lo = 0, hi = n;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(x <= t[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

I upper_b(I x) {
    I lo = 0, hi = n;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(x < t[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main()
{
    scanf("%i", &n);

    for(I i = 0; i < n; ++i) {
        scanf("%i", &t[i]);
    }

    I m;
    scanf("%i", &m);

    for(I i = 0; i < m; ++i) {
        I x;
        scanf("%i", &x);

        printf("%i\n", upper_b(x) - lower_b(x));

    }



    return 0;
}

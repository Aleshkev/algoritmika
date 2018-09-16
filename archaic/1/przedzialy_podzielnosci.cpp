#include <bits/stdc++.h>

using namespace std;

typedef int I;

I digsum(I n) {
    I c = 0;
    for(I i = 0; i < 7; ++i) {
        c += n % 10;
        n /= 10;
    }
    return c;
}

int main()
{
    I a, b; scanf("%i %i", &a, &b);
    I c = 0;
    for(I i = max(a, 1); i <= b; ++i) {
        if(i % digsum(i) == 0) {
            ++c;
        }
    }
    printf("%i", c);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I m;
    scanf("%li", &m);

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%li %li", &a, &b);

        I li = -b, mia = a;
        I g = __gcd(a, b);
        li /= g; mia /= g;
        if(li < 0 && mia < 0) li = abs(li), mia = abs(mia);

        if(mia == 1) {
            printf("%li\n", li);
        } else {
            printf("%li/%li\n", li, mia);
        }
    }

    return 0;
}

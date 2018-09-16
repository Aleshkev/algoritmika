#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n;
    scanf("%i", &n);

    multiset<I> prev;

    I c = 0;

    for(I i = 0; i < n; ++i) {
        I a;
        scanf("%i", &a);

        c += distance(prev.upper_bound(a), prev.end());

        prev.insert(a);
    }

    printf("%i\n", c);

    return 0;
}

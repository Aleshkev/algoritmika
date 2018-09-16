#include <bits/stdc++.h>

using namespace std;

typedef long int I;

I ngroups;
I t[1000000];

I find_root(I x) {
    if(t[x] != x) {
        t[x] = find_root(t[x]);
    }
    return t[x];
}

void join(I a, I b) {
    a = find_root(a), b = find_root(b);
    if(a == b) {
        return;
    }
    t[b] = a;
    --ngroups;
}

int main()
{
    I n, m;
    scanf("%li %li", &n, &m);

    for(I i = 0; i < n; ++i) {
        t[i] = i;
    }
    ngroups = n;

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%li %li", &a, &b);
        --a; --b;
        join(a, b);
    }

    printf("%li\n", ngroups);

    return 0;
}

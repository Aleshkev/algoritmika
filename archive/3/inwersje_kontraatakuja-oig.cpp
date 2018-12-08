#include <bits/stdc++.h>

using namespace std;

typedef long int I;

I n;
I t[60000], u[60000];
I w;
I tree[3000000];

void tree_add(I i, I val = 1) {
    I v = w + i;
    tree[v] += val;
    for(v /= 2; v > 0; v /= 2) {
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

I tree_get(I a, I b) {
    I va = w + a, vb = w + b;
    I c = tree[va];
    if(va != vb) c += tree[vb];
    while(va / 2 != vb / 2) {
        if(va % 2 == 0) c += tree[va + 1];
        if(vb % 2 == 1) c += tree[vb - 1];
        va /= 2; vb /= 2;
    }
    return c;
}

int main()
{
    scanf("%li", &n);
    for(I i = 0; i < n; ++i) {
        scanf("%li", &t[i]);
    }

    w = 1;
    while(w < n) w <<= 1;

    copy(t, t + n, u);
    sort(u, u + n);
    for(I i = 0; i < n; ++i) {
        t[i] = lower_bound(u, u + n, t[i]) - u;
    }

    I c = 0;
    for(I i = 0; i < n; ++i) {
        c += tree_get(t[i] + 1, w);
        tree_add(t[i]);
    }
    printf("%li", c);
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I n, m, w;
I sum[500000] = {0}, sq_sum[500000] = {0};

void tree_set(I *tree, I i, I val) {
    tree[w + i] = val;
    for(I j = (w + i) / 2; j >= 1; j /= 2) {
        tree[j] = tree[2 * j] + tree[2 * j + 1];
    }
}
I tree_get(I *tree, I a, I b) {
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
    cout.sync_with_stdio(false);

    cin >> n >> m;

    for(w = 1; w < n; w <<= 1);

    for(I i = 0; i < n; ++i) {
        I a;
        cin >> a;
        tree_set(sum, i, a);
        tree_set(sq_sum, i, a * a);
    }

    for(I i = 0; i < m; ++i) {
        I q, a, b;
        cin >> q >> a >> b;

        if(q == 0) {
            --a;
            tree_set(sum, a, b);
            tree_set(sq_sum, a, b * b);
        } else {
            --a; --b;
            I abc = tree_get(sum, a, b);
            I a2b2c2 = tree_get(sq_sum, a, b);
            cout << (abc * abc - a2b2c2) / 2 << '\n';
        }
    }

    return 0;
}

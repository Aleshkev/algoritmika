#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I n, q, w;
I tomatoes[100000];
I tree[5 + 1][300000];

void tree_set(I k, I i, I x) {
    I v = w + i;
    tree[k][v] = x;
    for(v /= 2; v > 0; v /= 2) {
        tree[k][v] = tree[k][2 * v] + tree[k][2 * v + 1];
    }
}
I tree_get(I k, I a, I b) {
    I va = w + a, vb = w + b;
    I c = tree[k][va];
    if(va != vb) c += tree[k][vb];
    while(va / 2 != vb / 2) {
        if(va % 2 == 0) c += tree[k][va + 1];
        if(vb % 2 == 1) c += tree[k][vb - 1];
        va /= 2; vb /= 2;
    }
    return c;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for(w = 1; w <= n; w <<= 1);

    for(I k = 1; k <= 5; ++k) {
        for(I i = 0; i < n; ++i) {
            tree_set(k, i, 1);
        }
    }

    for(I i = 0; i < q; ++i) {
        char cmd[8];
        cin >> cmd;
        if(cmd[0] == 'W') {
            I p, c;
            cin >> p >> c;
            --p;
            tomatoes[p] += c;
            for(I k = 1; k <= 5; ++k) {
                tree_set(k, p, tomatoes[p] % k == 0);
            }
        } else {
            I a, b, k;
            cin >> a >> b >> k;
            --a; --b;
            cout << tree_get(k, a, b) << '\n';
        }
    }

    return 0;
}

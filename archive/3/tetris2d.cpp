#include <bits/stdc++.h>

using namespace std;

typedef long int I;

I n, m, w;

I val[3000000], for_later[3000000];

I burnquery(I qb, I qe, I i, I rb, I re, I x) {
    if(qe < rb || qb > re) {
        return 0;
    }
    if(qb <= rb && re <= qe) {
        val[i] = max(val[i], x);
        for_later[i] = max(for_later[i], x);
        return val[i];
    }

    val[2 * i] = max(val[2 * i], for_later[i]);
    for_later[2 * i] = max(for_later[2 * i], for_later[i]);
    val[2 * i + 1] = max(val[2 * i + 1], for_later[i]);
    for_later[2 * i + 1] = max(for_later[2 * i + 1], for_later[i]);
    for_later[i] = 0;

    I mid = (rb + re) / 2;

    I result = max(burnquery(qb, qe, 2 * i, rb, mid, x),
                   burnquery(qb, qe, 2 * i + 1, mid + 1, re, x));
    val[i] = max(val[2 * i], val[2 * i + 1]);
    return result;
}
I tree_get(I qb, I qe) {
    return burnquery(qb, qe, 1, 0, w - 1, 0);
}
I tree_set(I qb, I qe, I x) {
    return burnquery(qb, qe, 1, 0, w - 1, x);
}

int main() {
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(w = 1; w <= n; w <<= 1);

    /*for(;;) {
        I a, b, x;
        cin >> a >> b >> x;
        tree_set(a, b, x);
        for(I i = 0; i < w; ++i) cout << tree_get(i, i) << ' '; cout << '\n';
    }*/

    for(I i = 0; i < m; ++i) {
        I l, x;
        cin >> l >> x;
        tree_set(x, x + l - 1, tree_get(x, x + l - 1) + 1);
        //for(I i = 1; i < 2 * w; ++i) {cout << val[i] << ' '; if(__builtin_popcount(i + 1) == 1) cout << '\n';} cout << "\n\n";
        //for(I i = 1; i < 2 * w; ++i) {cout << for_later[i] << ' '; if(__builtin_popcount(i + 1) == 1) cout << '\n';} cout << "\n\n";
        //for(I i = 0; i < w; ++i) cout << tree_get(i, i) << ' '; cout << '\n';
    }

    cout << tree_get(0, n) << '\n';


    return 0;
}

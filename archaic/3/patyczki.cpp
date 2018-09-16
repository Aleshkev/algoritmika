#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I n, w;

static I sum_tree[8400000], max_tree[8400000];
void tree_set(I i, I x) {
    I v = w + i;
    sum_tree[v] = max_tree[v] = x;
    for(v /= 2; v > 0; v /= 2) {
        sum_tree[v] = sum_tree[2 * v] + sum_tree[2 * v + 1];
        max_tree[v] = max(max_tree[2 * v], max_tree[2 * v + 1]);
    }
}
I sum_tree_get(I a, I b) {
    I va = w + a, vb = w + b;
    I c = sum_tree[va];
    if(va != vb) c += sum_tree[vb];
    while(va / 2 != vb / 2) {
        if(va % 2 == 0) c += sum_tree[va + 1];
        if(vb % 2 == 1) c += sum_tree[vb - 1];
        va /= 2; vb /= 2;
    }
    return c;
}
I max_tree_get(I a, I b) {
    I va = w + a, vb = w + b;
    I c = max(max_tree[va], max_tree[vb]);
    while(va / 2 != vb / 2) {
        if(va % 2 == 0) c = max(c, max_tree[va + 1]);
        if(vb % 2 == 1) c = max(c, max_tree[vb - 1]);
        va /= 2; vb /= 2;
    }
    return c;
}


int main()
{
    cout.sync_with_stdio(false);

    cin >> n;

    for(w = 1; w < n; w <<= 1);

    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;
        tree_set(i, x);
    }

    /*for(I i = 0; i < n; ++i) {
        cout << max_tree_get(i, i) << ' ';
    } cout << '\n';*/

    I p = 1;
    I m;
    cin >> m;
    for(I i = 0; i < m; ++i) {
        char c;
        I a, b;
        cin >> c >> a >> b;

        if(c == 'W') {
            --a; --b;
            I max_seg = max_tree_get(a, b);
            I sum_seg = sum_tree_get(a, b);
            //cout << max_seg << " " << sum_seg << '\n';
            cout << p << ' ' << (b - a + 1 > 2 && max_seg < sum_seg - max_seg ? "Ale czad!" : "Motyla noga...") << '\n';
            ++p;
        } else {
            --a;
            tree_set(a, max_tree_get(a, a) + b);
        }
    }

    return 0;
}

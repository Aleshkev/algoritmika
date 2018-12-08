#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

const I max_t = 1e6 + 1;

I n;
I om[300000], od[300000];
I omt[2100000], odt[2100000];

I w;

void tree_set(I *tree, I i, I x) {
    tree[w + i] = max(tree[w + i], x);
    for(I j = (w + i) / 2; j > 0; j /= 2) {
        tree[j] = max(tree[j * 2 + 0], tree[j * 2 + 1]);
    }
}
I tree_get(I *tree, I a, I b) {
    I va = w + a, vb = w + b;
    I c = max(tree[va], tree[vb]);
    for(; va / 2 != vb / 2; va /= 2, vb /= 2) {
        if(va % 2 == 0) c = max(c, tree[va + 1]);
        if(vb % 2 == 1) c = max(c, tree[vb - 1]);
    }
    return c;
}

int main() {
    cout.sync_with_stdio(false);
    cin.tie(0);

    w = 1;
    while(w < max_t) w <<= 1;

    /*for(;;) {
        I op, i, x;
        cin >> op >> i >> x;
        if(op == 0)
            tree_set(omt, i, x);
        else cout << tree_get(omt, i, x) << '\n';
        for(I i = 1; i < w * 2; ++i) {
            cout << omt[i] << ' ';
        } cout << endl;
    }*/

    cin >> n;


    I v;
    cin >> v;
    om[0] = od[0] = v;
    tree_set(omt, v, v);
    tree_set(odt, v, v);
    for(I i = 1; i < n; ++i) {
        cin >> v;
        om[i] = tree_get(odt, 0, v - 1) + v;
        od[i] = tree_get(omt, v + 1, max_t) + v;
        tree_set(omt, v, om[i]);
        tree_set(odt, v, od[i]);

        /*om[i] = t[i];
        for(I j = 0; j < i; ++j) {
            if(t[j] > t[i]) {
                om[i] = max(om[i], od[j] + t[i]);
            }
        }

        od[i] = t[i];
        for(I j = 0; j < i; ++j) {
            if(t[j] < t[i]) {
                od[i] = max(od[i], om[j] + t[i]);
            }
        }*/
    }

    //cout << " t = "; for(I i = 0; i < n; ++i) cout << setw(3) <<  t[i] << ' '; cout << '\n';
    //cout << "om = "; for(I i = 0; i < n; ++i) cout << setw(3) << om[i] << ' '; cout << '\n';
    //cout << "od = "; for(I i = 0; i < n; ++i) cout << setw(3) << od[i] << ' '; cout << '\n';

    cout << max(*max_element(om, om + n), *max_element(od, od + n));

    return 0;
}

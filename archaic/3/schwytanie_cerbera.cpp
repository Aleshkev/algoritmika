#include <bits/stdc++.h>

using namespace std;

typedef int I;

I n;
I original[1000000], result[1000000];
I tree[2500000], w;

void tree_set(I i, I val) {
    I v = w + i;
    tree[v] = val;
    for(v /= 2; v > 0; v /= 2) {
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}
I tree_kth(I k) {
    I v = 1;
    while(v < w) {
        if(k <= tree[2 * v]) {
            v = 2 * v;
        } else {
            k -= tree[2 * v];
            v = 2 * v + 1;
        }
    }
    return v - w;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(w = 1; w <= n; w *= 2);

    for(I i = 0; i < n; ++i) {
        cin >> original[i];
    }

    for(I i = 1; i <= n; ++i) {
        tree_set(i, 1);
    }

    for(I i = n - 1; i >= 0; --i) {
        result[i] = tree_kth(original[i] + 1);
        tree_set(result[i], 0);
    }

    for(I i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    } cout << '\n';

    return 0;
}

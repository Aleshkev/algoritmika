#include <bits/stdc++.h>

using namespace std;

typedef long int I;

struct Q {
    I x, y, z;
};

I tree[1 << 22];
I n, w = (1 << 21);

void tree_set(I i, I inc) {
    I v = w + i;
    tree[v] += inc;
    for(v /= 2; v >= 1; v /= 2) {
        tree[v] = tree[2 * v] + tree[2 * v + 1];
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
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<Q> q(n);
    vector<I> used_numbers;

    for(I i = 0; i < n; ++i) {
        I x, y, z;
        cin >> x >> y >> z;
        q[i].x = x; q[i].y = y; q[i].z = z;
        used_numbers.push_back(z);
        if(x == 0) used_numbers.push_back(y);
    }

    sort(used_numbers.begin(), used_numbers.end());

    for(I i = 0; i < n; ++i) {
        I x = q[i].x, y = q[i].y, z = q[i].z;

        z = lower_bound(used_numbers.begin(), used_numbers.end(), z) - used_numbers.begin();
        if(x == 0) y = lower_bound(used_numbers.begin(), used_numbers.end(), y) - used_numbers.begin();

        if(x == 1) {
            tree_set(z, y);
        } else if(x == 2) {
            if(tree_get(z, z) >= y) {
                cout << "OK\n";
                tree_set(z, -y);
            } else {
                cout << "NIE\n";
            }
        } else {
            cout << tree_get(y, z) << '\n';
        }
    }

    return 0;
}

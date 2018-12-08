// Przepiêkne rozwi¹zanie O(n log(n))

#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef long long int I;
typedef double F;

int main()
{
    cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    I *t = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    I *prefix_sums = new I[n];
    prefix_sums[0] = t[0];
    for(I i = 1; i < n; ++i) {
        prefix_sums[i] = prefix_sums[i - 1] + t[i];
    }


    I o = 1, c = 1;
    while(c < n) {
        c <<= 1;
        o += c;
    }
    ++o;

    // Drzewo przedzia³owe :D
    I *tree = new I[o];
    fill(tree, tree + o, 0);

    for(I i = 0; i < n; ++i) {
        I v = c + i;
        tree[c + i] = t[i];

        for(;;) {
            tree[v] = max(tree[v], t[i]);
            if(v == 1) {
                break;
            }
            v /= 2;
        }
    }


    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;

        I sum = prefix_sums[b] - (a > 0 ? prefix_sums[a - 1] : 0);

        I va = c + a, vb = c + b;
        I maxl = tree[va];
        if (va != vb && tree[vb] > maxl) {
            maxl = tree[vb];
        }
        while(va / 2 != vb / 2) {
            if (va % 2 == 0 && tree[va + 1] > maxl) {
                maxl = tree[va + 1];
            }
            if (vb % 2 == 1 && tree[vb - 1] > maxl) {
                maxl = tree[vb - 1];
            }

            va /= 2; vb /= 2;
        }

        if(maxl < (F)(sum) / 2.0) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}

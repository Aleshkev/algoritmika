#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I n, m, k;
I fau[500000], nphones[500000];
struct Edge {
    I a, b, t;
} edges[1000000];

I find_root(I x) {
    if(fau[x] != x) {
        fau[x] = find_root(fau[x]);
    }
    return fau[x];
}
I make_union(I a, I b) {
    I root_a = find_root(a), root_b = find_root(b);
    if(root_a != root_b) {
        fau[root_b] = root_a;
        nphones[root_a] += nphones[root_b];
        if(nphones[root_a] >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for(I i = 0; i < n; ++i) {
        fau[i] = i;
    }
    for(I i = 0; i < k; ++i) {
        I j;
        cin >> j;
        --j;
        ++nphones[j];
    }

    for(I i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].t;
        --edges[i].a; --edges[i].b;
    }
    sort(edges, edges + m, [](Edge a, Edge b){return a.t > b.t; });

    if(k == 1) {
        cout << "KEEP CALM AND FOLLOW THE WHITE RABBIT\n";
    } else {
        bool all_ok = true;
        for(I i = 0; i < m; ++i) {
            if(make_union(edges[i].a, edges[i].b)) {
                cout << edges[i].t - 1 << '\n';
                all_ok = false;
                break;
            }
        }
        if(all_ok) {
            cout << "-1\n";
        }
    }

    return 0;
}

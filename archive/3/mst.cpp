#include <bits/stdc++.h>

using namespace std;

typedef long int I;
typedef pair<I, I> II;

struct Edge {
    I a, b;
    I w;
    I i;
};
bool operator<(Edge x, Edge y) {
    return x.w < y.w;
}

I find_root(vector<I> &fau, I x) {
    if(fau[x] != x) {
        fau[x] = find_root(fau, fau[x]);
    }
    return fau[x];
}
bool unite(vector<I> &fau, I a, I b) {
    I root_a = find_root(fau, a), root_b = find_root(fau, b);
    if(root_a != root_b) {
        fau[root_b] = root_a;
        return true;
    }
    return false;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(I i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        --edges[i].a; --edges[i].b;
        edges[i].i = i + 1;
    }
    sort(edges.begin(), edges.end());

    vector<I> fau(n);
    for(I i = 0; i < n; ++i) {
        fau[i] = i;
    }

    for(I i = 0; i < m; ++i) {
        if(unite(fau, edges[i].a, edges[i].b)) {
            cout << edges[i].i << '\n';
        }
    }

    return 0;
}

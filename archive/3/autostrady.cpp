#include <bits/stdc++.h>

using namespace std;

const int64_t inf = 1e18;

struct Offer {
    int32_t start, stop;
    int64_t cost;
};

int32_t w;
int64_t tree[3000000];

void tree_set(int32_t i, int64_t x) {
    int32_t j = w + i;
    if(x > tree[j]) {
        return;
    }
    tree[j] = x;
    for(j /= 2; j > 0; j /= 2) {
        tree[j] = min(tree[2 * j], tree[2 * j + 1]);
    }
}
int64_t tree_get(int32_t qb, int32_t qe, int32_t i, int32_t rb, int32_t re) {
    if(re < qb || qe < rb) {
        return inf;
    }
    if(qb <= rb && re <= qe) {
        return tree[i];
    }
    int32_t mid = (rb + re) / 2;
    return min(tree_get(qb, qe, 2 * i, rb, mid),
               tree_get(qb, qe, 2 * i + 1, mid + 1, re));
}
int64_t tree_get(int32_t b, int32_t e) {
    return tree_get(b, e, 1, 0, w - 1);
}

bool by_stop(const Offer &a, const Offer &b) {
    return a.stop < b.stop;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int32_t n, m;
    cin >> n >> m;

    static Offer offers[1000000];
    for(int32_t i = 0; i < m; ++i) {
        cin >> offers[i].start >> offers[i].stop >> offers[i].cost;
    }
    sort(offers, offers + m, by_stop);

    for(w = 1; w <= n; w <<= 1);
    fill(tree, tree + 2 * w, inf);
    tree_set(0, 0);

    for(int32_t i = 0; i < m; ++i) {
        tree_set(offers[i].stop, tree_get(offers[i].start, offers[i].stop) + offers[i].cost);
    }

    cout << tree_get(n, n) << '\n';

    return 0;
}

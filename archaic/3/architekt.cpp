#include <bits/stdc++.h>

using namespace std;

typedef long int I;

I n, m;
I parent[100000];
I dist[100000];

I find_root(I x) {
    I root = x, root_d = 0;
    while(parent[root] != root) {
        root_d += dist[root];
        root = parent[root];
    }

    parent[x] = root;
    dist[x] = root_d;

    return root;
}

bool make_union(I lo, I hi, I d) {
    I root_lo = find_root(lo), root_hi = find_root(hi);

    if(root_lo == root_hi) {
        return dist[lo] - dist[hi] == d;
    } else {
        parent[root_lo] = root_hi;
        dist[root_lo] = d + dist[hi] - dist[lo];

        return true;
    }
}

int main() {
    scanf("%li %li", &n, &m);

    for(I i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for(I i = 0; i < m; ++i) {
        I lo, hi, w;
        scanf("%li %li %li", &hi, &lo, &w);
        --lo; --hi;

        printf("%s\n", (make_union(lo, hi, w) ? "TAK" : "NIE"));
    }


    return 0;
}

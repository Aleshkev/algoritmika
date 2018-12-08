#include <iostream>
#include <set>

using namespace std;

typedef int I;

I tg;
I t[1000000];

I root(I a) {
    if(t[a] != a) {
        t[a] = root(t[a]);
    }
    return t[a];
}

void unite(I a, I b) {
    I root_a = root(a), root_b = root(b);
    if(root_a == root_b) return;
    t[root_a] = root_b;
}

int main()
{
    cout.sync_with_stdio(false);

    I n; cin >> n;
    tg = n;

    for(I i = 0; i < n; ++i) {
        I parent; cin >> parent; --parent;
        if(parent == -1) parent = i;
        t[i] = parent;
    }

    set<I> uq;

    I m; cin >> m;
    for(I i = 0; i < m; ++i) {
        I k; cin >> k; --k;
        uq.insert(root(t[k]));
    }

    cout << uq.size() << '\n';


    return 0;
}

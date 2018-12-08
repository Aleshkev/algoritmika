#include <bits/stdc++.h>

using namespace std;

typedef long int I;

I n, m;
I t[1000001];
I find_root(I x) {
    if(t[x] != x) {
        t[x] = find_root(t[x]);
    }
    return t[x];
}
void unite(I a, I b) {
    a = find_root(a);
    b = find_root(b);
    if(a != b) {
        t[b] = a;
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(I i = 1; i <= n; ++i) {
        t[i] = i;
    }

    for(I i = 1; i <= n; ++i) {
        I x;
        cin >> x;

        if(i - x >= 1) {
            unite(i, i - x);
        }
        if(i + x <= n) {
            unite(i, i + x);
        }
    }

    /*for(I i = 1; i <= n; ++i) {
        cout << find_root(i) << ' ';
    } cout << '\n';*/

    cin >> m;
    for(I i = 1; i <= m; ++i) {
        I a, b;
        cin >> a >> b;

        cout << (find_root(a) == find_root(b) ? "TAK" : "NIE") << '\n';
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

typedef int I;
typedef unsigned U;

struct Station {
    U i;
    I x, y;
};
bool by_x(const Station &l, const Station &r) { return l.x < r.x; };
bool by_y(const Station &l, const Station &r) { return l.y < r.y; };

Station *t;
U *f;

U find_root(U a) {
    if(a != f[a]) {
        f[a] = find_root(f[a]);
    }
    return f[a];
}

void make_union(U a, U b) {
    U root_a = find_root(a), root_b = find_root(b);
    if(root_a != root_b) {
        f[root_a] = root_b;
    }
}

int main()
{
    U n;
    cin >> n;

    t = new Station[n];
    f = new U[n];
    for(U i = 0; i < n; ++i) {
        cin >> t[i].x >> t[i].y;
        t[i].i = i;
        f[i] = i;
    }

    sort(t, t + n, by_x);
    for(U i = 0; i < n - 1; ++i) {
        if(t[i].x == t[i + 1].x) {
            make_union(t[i].i, t[i + 1].i);
        }
    }

    sort(t, t + n, by_y);
    for(U i = 0; i < n - 1; ++i) {
        if(t[i].y == t[i + 1].y) {
            make_union(t[i].i, t[i + 1].i);
        }
    }

    U m;
    cin >> m;

    for(U i = 0; i < m; ++i) {
        U a, b;
        cin >> a >> b;
        --a; --b;
        cout << (find_root(a) == find_root(b) ? "TAK" : "NIE") << "\n";
    }



    return 0;
}

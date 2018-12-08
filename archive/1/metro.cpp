#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned U;
typedef int I;

struct Station {
    U i;
    I x, y;
};
bool by_x(const Station &l, const Station &r) { return l.x < r.x; }
bool by_y(const Station &l, const Station &r) { return l.y < r.y; }

Station *t;
U *f;

U find_root(U a) {
    U b = a;
    while(a != f[a]) {
        a = f[a];
    }
    while(b != f[b]) {
        U p = f[b];
        f[b] = a;
        b = p;
    }
    return a;
}
void make_union(U a, U b) {
    U root_a = find_root(a), root_b = find_root(b);
    if(root_a != root_b) {
        f[root_b] = root_a;
    }
}

int main()
{
    U n, m;  // Liczba dzieci, liczba pytan
    //cin >> n >> m;
    scanf("%u %u", &n, &m);

    t = new Station[n];
    f = new U[n];

    for(U i = 0; i < n; ++i) {
        scanf("%i %i", &t[i].x, &t[i].y);
        //cin >> t[i].x >> t[i].y;
        t[i].i = f[i] = i;
    }

    sort(t, t + n, by_x);
    for(U i = 1; i < n; ++i) {
        if(t[i].x == t[i - 1].x) {
            make_union(t[i].i, t[i - 1].i);
        }
    }

    sort(t, t + n, by_y);
    for(U i = 1; i < n; ++i) {
        if(t[i].y == t[i - 1].y) {
            make_union(t[i].i, t[i - 1].i);
        }
    }

    for(U i = 0; i < m; ++i) {
        U a, b;
        scanf("%u %u", &a, &b);
        //cin >> a >> b;
        --a; --b;
        printf("%s\n", (find_root(a) == find_root(b) ? "TAK" : "NIE"));
        //cout << (find_root(a) == find_root(b) ? "TAK\n" : "NIE\n");
    }

    return 0;
}

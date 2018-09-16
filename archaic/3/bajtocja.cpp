#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Edge {
    I i;
    I a, b;
    I cost;
    bool accepted;
};
bool by_cost(const Edge &l, const Edge &r) {
    return l.cost < r.cost;
}
bool by_i(const Edge &l, const Edge &r) {
    return l.i < r.i;
}

Edge edges[300000];
I t[7000];

I find_root(I x) {
    cout << "r";
    if(x != t[x]) {
        t[x] = find_root(t[x]);
    }
    return t[x];
}

bool make_union(I x, I y) {
    cout << "m";
    I root_x = find_root(x), root_y = find_root(y);
    if(root_x == root_y) {
        return false;
    }

    t[x] = y;
    return true;
}

int main()
{
    //cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    for(I i = 0; i < m; ++i) {
        edges[i].i = i;
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
        --edges[i].a; --edges[i].b;
        edges[i].accepted = false;
    }
    sort(edges, edges + m, by_cost);

    for(I i = 0; i < m; ++i) {
        t[i] = i;
    }

    cout << "i:    ";
    for(I i = 0; i < m; ++i) {
        cout << setw(2) << i << ' ';
    } cout << '\n';
    cout << "a:    ";
    for(I i = 0; i < m; ++i) {
        cout << setw(2) << edges[i].a << ' ';
    } cout << '\n';
    cout << "b:    ";
    for(I i = 0; i < m; ++i) {
        cout << setw(2) << edges[i].b << ' ';
    } cout << '\n';
    cout << "cost: ";
    for(I i = 0; i < m; ++i) {
        cout << setw(2) << edges[i].cost << ' ';
    } cout << endl;

    make_union(edges[0].a, edges[0].b);
    edges[0].accepted = true;
    I master_root = find_root(edges[0].a);

    for(I i = 1; i < m; ++i) {
        cout << "i";
        edges[i].accepted = make_union(edges[i].a, edges[i].b);
    }

    sort(edges, edges + m, by_i);

    for(I i = 0; i < m; ++i) {
        cout << (edges[i].accepted ? "TAK" : "NIE") << '\n';
    }

    return 0;
}

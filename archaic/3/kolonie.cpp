#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Cell {
    I weight;
    I min_iq, max_iq;
};

I n;
Cell cells[1000000];
I t[1000000];

I find_root(I a) {
    if(t[a] != a) {
        t[a] = find_root(t[a]);
    }
    return t[a];
}

void join(I a, I b) {
    I root_a = find_root(a), root_b = find_root(b);
    if(root_a == root_b) return;
    t[root_b] = root_a;
    auto &cell_a = cells[root_a], &cell_b = cells[root_b];
    cell_a.min_iq = min(cell_a.min_iq, cell_b.min_iq);
    cell_a.max_iq = max(cell_a.max_iq, cell_b.max_iq);
    cell_a.weight = cell_a.weight + cell_b.weight;
}

int main()
{
    cin >> n;

    for(I i = 0; i < n; ++i) {
        cin >> cells[i].weight >> cells[i].min_iq;
        cells[i].max_iq = cells[i].min_iq;
        t[i] = i;
    }

    string cmd;
    while(cin >> cmd) {
        if(cmd == "JOIN") {
            I a, b;
            cin >> a >> b;
            --a; --b;
            join(a, b);
        } else {
            I a;
            cin >> a;
            --a;
            auto &cell = cells[find_root(a)];
            I val;
            if(cmd == "IQ_MIN") {
                val = cell.min_iq;
            } else if(cmd == "IQ_MAX") {
                val = cell.max_iq;
            } else {
                val = cell.weight;
            }
            cout << val << '\n';
        }
    }

    return 0;
}

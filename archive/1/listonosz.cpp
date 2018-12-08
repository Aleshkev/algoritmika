#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Connection {
    I to;
    bool forced;
    Connection(I to_, bool forced_ = false) : to(to_), forced(forced_) {};
};
bool operator<(const Connection &l, const Connection &r) { return l.to < r.to; };
bool operator==(const Connection &l, const Connection &r) { return l.to == r.to; };

int main()
{
    I n, m;
    cin >> n >> m;

    static vector<Connection> graph[50000];
    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(Connection(b));
    }

    I k;
    cin >> k;

    for(I i = 0; i < k; ++i) {
        I l;
        cin >> l;
        I last;
        cin >> last;
        --last;
        for(I j = 1; j < l; ++j) {
            I that;
            cin >> that;
            --that;

            find(graph[last].begin(), graph[last].end(), Connection(that))->forced = true;

            last = that;
        }
    }

    for(I i = 0; i < n; ++i) {
        cout << i << ": ";
        for(I j = 0; j < graph[i].size(); ++j) {
            cout << graph[i][j].to << (graph[i][j].forced ? "(F) " : " ");
        } cout << endl;
    }

    return 0;
}

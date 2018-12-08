#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = 1e18;

vector<I> &bfs(const vector<vector<I> > &graph, I start = 0) {
    queue<I> q;
    q.push(start);
    vector<I> &lvl = *(new vector<I>(graph.size()));
    fill(lvl.begin(), lvl.end(), inf);
    lvl[start] = 0;

    while(!q.empty()) {
        I a = q.front();
        q.pop();

        for(I b : graph[a]) {
            if(lvl[a] + 1 < lvl[b]) {
                lvl[b] = lvl[a] + 1;
                q.push(b);
            }
        }
    }

    return lvl;
}


int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I n;
    cin >> n;

    vector<vector<I> > graph(n);

    for(I i = 0; i < n - 1; ++i) {
        I a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto &l1 = bfs(graph, 0);

    I beg = distance(l1.begin(), max_element(l1.begin(), l1.end()));

    auto &l2 = bfs(graph, beg);

    I en = distance(l2.begin(), max_element(l2.begin(), l2.end()));
    I f1 = l2[en] / 2, f2 = l2[en] - f1;

    for(I i = 0; i < n; ++i) {
        if(l1[i] == f1 && l2[i] == f2) {
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    vector<vector<I>> graph(n), weights(n);

    for(I i = 0; i < n - 1; ++i) {
        I a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        graph[a].push_back(b);
        weights[a].push_back(w);
        graph[b].push_back(a);
        weights[b].push_back(w);
    }

vector<bool> visited(n);
vector<I> path(n);
vector<I> dfs;
dfs.push_back(0);
visited[0] = true;
while(!dfs.empty()) {
    I current = dfs.back();
    dfs.pop_back();

    for(I i = 0; i < graph[current].size(); ++i) {
        if(visited[graph[current][i]]) {
            continue;
        }
        dfs.push_back(graph[current][i]);
        path[graph[current][i]] = (path[current] ^ weights[current][i]);
        visited[graph[current][i]] = true;
    }
}

    for(I i = 0; i < n; ++i) {
        I a;
        cin >> a;
        --a;
        cout << path[a] << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = I(1e18);
typedef pair<I, I> II;

struct Edge {
    I to, weight;
    Edge(I to, I weight) : to(to), weight(weight) {};
};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for(I i = 0; i < m; ++i) {
        I a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        if(a >= n || b >= n) {
            return -1;
        }
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    vector<I> min_dist(n, inf);
    min_dist[0] = 0;

    vector<I> prev(n, -1);

    set<II> q;
    q.emplace(0, 0);

    while(!q.empty()) {
        I current = q.begin()->second;
        q.erase(q.begin());

        for(I i = 0; i < graph[current].size(); ++i) {
            auto &edge = graph[current][i];
            if(min_dist[edge.to] > min_dist[current] + edge.weight) {
                q.erase({min_dist[edge.to], edge.to});
                min_dist[edge.to] = min_dist[current] + edge.weight;
                q.insert({min_dist[edge.to], edge.to});
                prev[edge.to] = current;
            }
        }
    }

    vector<I> path;
    for(I current = n - 1; current != 0; current = prev[current]) {
        path.push_back(current);
    }
    path.push_back(0);
    reverse(path.begin(), path.end());

    I max_w = 0;
    for(I i = 0; i < path.size() - 1; ++i) {
        for(auto e : graph[i]) {
            if(e.to == path[i + 1]) {
                max_w = max(max_w, e.weight);
            }
        }
    }

    I d = min_dist[n - 1];
    if(d == inf) {
        cout << "OTÓŻ NIE\n";
    } else {
        cout << "WINCYJ ZADAŃ!\n" << min_dist[n - 1] - max_w + 1 << '\n';
    }


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<II>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b, v;
    cin >> a >> b >> v;
    --a, --b;
    if (a == b) continue;
    graph[a].push_back({v, b}), graph[b].push_back({v, a});
  }

  vector<I> d(n, inf);
  {
    deque<I> bfs = {n - 1};
    d[n - 1] = 0;
    while (!bfs.empty()) {
      I i = bfs.front();
      bfs.pop_front();
      for (II p : graph[i]) {
        I j = p.second;
        if (d[j] <= d[i] + 1) continue;
        d[j] = d[i] + 1;
        bfs.push_back(j);
      }
    }
  }

  vector<I> weights;
  vector<I> pos = {0};
  while (*max_element(pos.begin(), pos.end()) != n - 1) {
    vector<II> edges;
    for (I i : pos) {
      for (II p : graph[i]) {
        if (d[p.second] != d[i] - 1) continue;
        if (!edges.empty() && edges[0].first > p.first) edges.clear();
        if (edges.empty() || edges[0].first == p.first) edges.push_back(p);
      }
    }
    weights.push_back(edges[0].first);
    pos.clear();
    for (II p : edges) pos.push_back(p.second);
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
  }

  cout << weights.size() << "\n";
  for (I x : weights) cout << x << " ";
  cout << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

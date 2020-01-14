#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<I>> graph(n), loose_graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b);
    loose_graph[a].push_back(b), loose_graph[b].push_back(a);
  }

  vector<bool> loose_visited(n), visited(n);
  vector<I> incoming(n);
  for (I i = 0; i < n; ++i) {
    for (I j : graph[i]) ++incoming[j];
  }

  I sum_r = 0;
  for (I i = 0; i < n; ++i) {
    if (loose_visited[i]) continue;
    loose_visited[i] = true;
    vector<I> loose_dfs = {i};
    vector<I> loose_nodes;
    while (!loose_dfs.empty()) {
      I a = loose_dfs.back();
      loose_dfs.pop_back();
      loose_nodes.push_back(a);
      for (I b : loose_graph[a]) {
        if (loose_visited[b]) continue;
        loose_visited[b] = true;
        loose_dfs.push_back(b);
      }
    }

    vector<I> dfs;
    vector<I> nodes;
    for (I a : loose_nodes)
      if (incoming[a] == 0) dfs.push_back(a);

    while (!dfs.empty()) {
      I a = dfs.back();
      dfs.pop_back();
      nodes.push_back(a);
      for (I b : graph[a]) {
        --incoming[b];
        if (incoming[b] == 0) dfs.push_back(b);
      }
    }

    sum_r += (loose_nodes.size() == nodes.size() ? loose_nodes.size() - 1
                                                 : loose_nodes.size());
  }
  cout << sum_r << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

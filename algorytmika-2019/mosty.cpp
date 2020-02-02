#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<bool> edge_used(m);
  vector<vector<II>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back({b, i}), graph[b].push_back({a, i});
  }

  vector<I> depth(n, inf), low(n, 0);

  function<void(I)> dfs = [&](I i) {
    low[i] = depth[i];
    for (auto [j, e] : graph[i]) {
      if (depth[j] < depth[i] - 1) low[i] = min(low[i], depth[j]);
      if (depth[j] != inf) continue;
      depth[j] = depth[i] + 1;
      dfs(j);
      low[i] = min(low[i], low[j]);
    }
  };

  for (I i = 0; i < n; ++i) {
    if (depth[i] < inf) continue;
    depth[i] = 0;
    dfs(i);
  }

  vector<I> r;
  for (I i = 0; i < n; ++i) {
    if (low[i] != depth[i]) continue;
    for (auto [j, e] : graph[i]) {
      if (depth[j] == depth[i] - 1) {
        r.push_back(e);
        break;
      }
    }
  }
  sort(r.begin(), r.end());
  cout << r.size() << "\n";
  for (I e : r) cout << e + 1 << " ";
  cout << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

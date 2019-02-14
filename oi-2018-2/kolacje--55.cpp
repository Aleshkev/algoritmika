#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef long double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  I n, r;
  cin >> n >> r;

  vector<vector<I>> places_of_type(r);
  for (I i = 0; i < n; ++i) {
    I t;
    cin >> t;
    --t;
    places_of_type[t].push_back(i);
  }

  vector<vector<II>> graph(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    graph[a].push_back({b, c}), graph[b].push_back({a, c});
  }

  vector<I> partial_cost(n), depth(n);
  partial_cost[0] = depth[0] = 0;
  const I log_n = ceil(log2((F)n)) + 1;
  vector<vector<I>> parent(n, vector<I>(log_n, -1));

  {
    vector<bool> visited(n);
    visited[0] = true;

    function<void(I)> dfs = [&](I i) {
      for (I k = 1; k < log_n; ++k) {
        if (parent[i][k - 1] == -1) break;
        parent[i][k] = parent[parent[i][k - 1]][k - 1];
        if (parent[i][k] == -1) break;
      }

      for (II e : graph[i]) {
        I j = e.first, c = e.second;
        if (visited[j]) continue;
        visited[j] = true;

        parent[j][0] = i;
        depth[j] = depth[i] + 1;
        partial_cost[j] = partial_cost[i] + c;

        dfs(j);
      }
    };
    dfs(0);
  }

  auto lca = [&](I a, I b) {
    if (depth[b] > depth[a]) swap(a, b);

    for (I i = log_n - 1; i >= 0; --i) {
      if (depth[a] - (1 << i) >= depth[b]) {
        a = parent[a][i];
      }
    }
    if (a != b) {
      for (I i = log_n - 1; i >= 0; --i) {
        if (parent[a][i] != parent[b][i]) {
          a = parent[a][i], b = parent[b][i];
        }
      }
      a = parent[a][0], b = parent[b][0];
    }

    assert(a == b);
    return a;
  };

  I q;
  cin >> q;
  for (I qi = 0; qi < q; ++qi) {
    I a, b, t;
    cin >> a >> b >> t;
    --a, --b, --t;

    if (places_of_type[t].empty()) {
      cout << "-1" << '\n';
      continue;
    }

    if (r == 1) {
      I p = lca(a, b);
      I x = partial_cost[a] + partial_cost[b] - 2 * partial_cost[p];
      cout << x << '\n';
      continue;
    }

    I min_x = inf;
    for (I i : places_of_type[t]) {
      I p = lca(a, i);
      I x = partial_cost[a] + partial_cost[i] - 2 * partial_cost[p];
      I q = lca(b, i);
      x += partial_cost[b] + partial_cost[i] - 2 * partial_cost[q];
      min_x = min(min_x, x);
    }
    cout << min_x << '\n';
  }

  return 0;
}
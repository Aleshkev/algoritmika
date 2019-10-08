#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

template <typename T>
T &from_end(vector<T> &v, I i) {
  return v[v.size() - i - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k;
  cin >> n >> k;

  vector<vector<I>> graph(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<vector<I>> tree(n);
  vector<I> max_depth(n);
  {
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[j] || !(visited[j] = true)) continue;
        tree[i].push_back(j);
        dfs(j);
        max_depth[i] = max(max_depth[i], max_depth[j] + 1);
      }
      sort(tree[i].begin(), tree[i].end(),
           [&](I x, I y) { return max_depth[x] < max_depth[y]; });
    };
    visited[0] = true, dfs(0);
  }

  int64_t c = 0;

  function<vector<I>(I)> dfs = [&](I i) {
    if (tree[i].empty()) return vector<I>{1};

    vector<vector<I>> d;
    for (I j : tree[i]) d.push_back(move(dfs(j)));

    for (auto &u : d) {
      if (k > u.size()) continue;
      c += from_end(u, k - 1);
    }

    auto v = d.back();
    d.pop_back();
    for (auto &u : d) {
      for (I x = 1; x < k && x <= u.size(); ++x) {
        if (k - x > v.size()) continue;
        c += from_end(u, x - 1) * from_end(v, k - x - 1);
      }

      for (I j = 0; j < u.size(); ++j) {
        from_end(v, j) += from_end(u, j);
      }
    }
    v.push_back(1);

    return v;
  };
  dfs(0);

  cout << c << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

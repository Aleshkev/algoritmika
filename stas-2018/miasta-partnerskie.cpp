#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<I>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<vector<I>> tree(n);
  {
    vector<bool> visited(n);
    vector<I> q = {0};
    visited[0] = true;
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        tree[i].push_back(j);
        q.push_back(j);
      }
    }
  }

  const I mod = 1000000007;
  vector<I> ans(n);
  vector<vector<I>> mul(n);
  function<void(I)> dfs = [&](I i) {
    mul[i].resize(tree[i].size());
    for (I k = (I)tree[i].size() - 1; k >= 0; --k) {
      I j = tree[i][k];
      dfs(j);
      mul[i][k] = (k < tree[i].size() - 1 ? mul[i][k + 1] : 1) * ans[j] % mod;
    }
    if (tree[i].size() < 1) {
      mul[i].push_back(1);
      ans[i] = 1;
      return;
    }
    ans[i] += mul[i][0];

    I s = 1;
    for (I k = 0; k < tree[i].size(); ++k) {
      I j = tree[i][k];
      ans[i] += s * mul[j][0] % mod *
                (k < tree[i].size() - 1 ? mul[i][k + 1] : 1) % mod;
      s = s * ans[j] % mod;
    }
    ans[i] %= mod;
  };
  dfs(0);
  cout << ans[0] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

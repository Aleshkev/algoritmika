#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I f_search(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (f(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<vector<I>> graph(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<vector<I>> tree(n);
  vector<bool> visited(n);
  vector<I> q = {0};
  visited[0] = true;
  while (!q.empty()) {
    I i = q.back();
    q.pop_back();
    for (I j : graph[i]) {
      if (visited[j]) continue;
      visited[j] = true;
      q.push_back(j);
      tree[i].push_back(j);
    }
  }

  auto enough = [&](I x) {
    if (x == 0) return n == 1;

    vector<I> dp(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : tree[i]) {
        dfs(j);
        dp[i] += dp[j] + 1;
      }
      dp[i] = max(dp[i] - x, (I)0);
    };
    dfs(0);
    return dp[0] == 0;
  };

  cout << f_search(0, n, [&](I x) { return !enough(x); }) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  I n, m, capital;
  cin >> n >> m >> capital;
  --capital;

  vector<vector<I>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<I> depth(n, 0), low(n, 0);
  vector<I> increment(n);

  {
    vector<bool> visited(n, false);
    function<void(I i)> dfs = [&](I i) {
      for (I other : graph[i]) {
        if (visited[other]) {
          low[i] = max(low[i], depth[i] - depth[other]);
          continue;
        }
        visited[other] = true;

        depth[other] = depth[i] + 1;
        dfs(other);
        low[i] = max(low[i], low[other] - 1);
        if (i != capital && low[other] <= 1) ++increment[other];
      }
    };
    visited[capital] = true;
    dfs(capital);
  }

  vector<I> score(n);
  {
    vector<bool> visited(n, false);
    function<void(I i)> dfs = [&](I i) {
      score[i] += increment[i];
      for (I other : graph[i]) {
        if (visited[other]) continue;
        visited[other] = true;

        score[other] += score[i];
        dfs(other);
      }
    };
    dfs(capital);
  }

  for (I i : score) cout << i << ' ';
  cout << '\n';

  return 0;
}

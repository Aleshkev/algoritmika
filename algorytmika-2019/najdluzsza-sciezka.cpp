#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

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

  I root = 0;
  {
    vector<I> depth(n);
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;

        depth[j] = depth[i] + 1;
        dfs(j);
      }
    };
    visited[0] = true;
    dfs(0);

    for (I i = 0; i < n; ++i)
      if (depth[i] > depth[root]) root = i;
  }

  vector<I> parent(n, -1);
  vector<I> depth(n);
  {
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        depth[j] = depth[i] + 1;
        dfs(j);
      }
    };
    visited[root] = true;
    dfs(root);
  }

  I toor = 0;  // Odwrotność 'root'.
  for (I i = 0; i < n; ++i)
    if (depth[i] > depth[toor]) toor = i;

  cout << depth[toor] << "\n";

  for (I current = toor; current != root; current = parent[current])
    cout << current + 1 << " ";
  cout << root + 1 << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

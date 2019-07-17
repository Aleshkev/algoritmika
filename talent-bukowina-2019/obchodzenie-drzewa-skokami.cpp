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

  vector<vector<I>> children(n);
  vector<I> parent(n);

  vector<I> dfs_queue = {0};
  vector<bool> visited(n);
  visited[0] = true;
  while (!dfs_queue.empty()) {
    I i = dfs_queue.back();
    dfs_queue.pop_back();
    for (I j : graph[i]) {
      if (visited[j]) continue;
      visited[j] = true;
      children[i].push_back(j);
      parent[j] = i;
      dfs_queue.push_back(j);
    }
  }

  vector<bool> filled(n);

  vector<I> fill_order;
  auto fill = [&](I i) {
    if (filled[i]) return;
    filled[i] = true;
    fill_order.push_back(i);
  };

  function<void(I)> dfs = [&](I i) {
    if (i == 0 || !filled[parent[i]]) {
      fill(i);
    }
    for (I j : children[i]) {
      dfs(j);
    }
    fill(i);
  };
  dfs(0);

  for (I i : fill_order) cout << i + 1 << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

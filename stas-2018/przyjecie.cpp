#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<I>> graph(2 * n);
  auto make_edge = [&](I a, I b) {
    graph[a].push_back(b), graph[b].push_back(a);
  };
  for (I i = 0; i < n; ++i) {
    make_edge(2 * i, 2 * i + 1);
  }

  vector<I> pos(2 * n);
  for (I i = 0; i < n; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    pos[2 * i] = a, pos[2 * i + 1] = b;
    make_edge(a, b);
  }

  vector<I> layer(2 * n, -1);
  auto dfs = [&](I i) {
    vector<I> q = {i};
    layer[i] = 0;
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();

      for (I j : graph[i]) {
        if (layer[j] != -1) continue;
        layer[j] = !layer[i];
        q.push_back(j);
      }
    }
  };
  for (I i = 0; i < 2 * n; ++i) {
    if (layer[i] != -1) continue;
    dfs(i);
  }

  for (I i = 0; i < n; ++i) {
    cout << layer[pos[2 * i]] + 1 << ' ' << layer[pos[2 * i + 1]] + 1 << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

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
  I root = find_if(graph.begin(), graph.end(),
                   [&](auto &i) { return i.size() == 1; }) -
           graph.begin();
  {
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        children[i].push_back(j);
        dfs(j);
      }
    };
    visited[root] = true, dfs(root);
  }

  vector<I> straight(n), bent(n);
  function<void(I)> dfs = [&](I i) {
    if (children[i].empty()) return;

    for (I j : children[i]) dfs(j);

    sort(children[i].begin(), children[i].end(), [&](I a, I b) {
      return straight[a] - bent[a] < straight[b] - bent[b];
    });
    I sum_bent = 0;
    for (I j : children[i]) sum_bent += bent[j] + 1;
    I a = children[i][0], b = (children[i].size() > 1 ? children[i][1] : -1);
    straight[i] = sum_bent - bent[a] + straight[a] - 1;

    if (b == -1)
      bent[i] = inf;
    else
      bent[i] = sum_bent - bent[a] + straight[a] - bent[b] + straight[b] - 2;

    bent[i] = min(bent[i], straight[i]);
  };
  dfs(root);

  cout << bent[root] + 1 << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

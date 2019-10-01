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
  vector<vector<I>> tree(n);
  {
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        tree[i].push_back(j);
        dfs(j);
      }
    };
    visited[0] = true;
    dfs(0);
  }

  vector<I> incl(n), excl(n);
  {
    function<void(I)> dfs = [&](I i) {
      incl[i] = 1;
      excl[i] = 0;
      for (I j : tree[i]) {
        dfs(j);
        incl[i] += excl[j];
        excl[i] += max(incl[j], excl[j]);
      }
    };
    dfs(0);
  }

  cout << max(incl[0], excl[0]) << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

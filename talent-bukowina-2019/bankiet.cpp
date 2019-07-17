#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<I>> graph(n);
  for (I a = 0; a < n; ++a) {
    I b;
    cin >> b;
    --b;

    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<bool> visited(n);
  I k = 0;
  for (I i = 0; i < n; ++i) {
    if (visited[i]) continue;
    ++k;
    vector<I> dfs = {i};
    while (!dfs.empty()) {
      I i = dfs.back();
      dfs.pop_back();

      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        dfs.push_back(j);
      }
    }
  }
  cout << k << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

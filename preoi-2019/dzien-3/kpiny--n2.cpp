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

  for (I origin = 0; origin < n; ++origin) {
    vector<vector<I>> children(n);

    vector<I> dfs = {origin};
    vector<bool> visited(n, false);
    visited[origin] = true;
    while (!dfs.empty()) {
      I i = dfs.back();
      dfs.pop_back();

      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        children[i].push_back(j);
        dfs.push_back(j);
      }
    }

    vector<I> v(n);
    function<void(I)> f = [&](I i) {
      bool any_losing = false;
      for (I j : children[i]) {
        f(j);
        if (v[j] == false) any_losing = true;
      }
      v[i] = any_losing;
    };
    f(origin);

    cout << (v[origin] ? "Partycja" : "Bajtek") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

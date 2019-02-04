#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;

  while (q--) {
    I n, k;
    cin >> n >> k;
    --k;

    vector<vector<II>> graph(n);
    for (I i = 0; i < n - 1; ++i) {
      I a, b, c;
      cin >> a >> b >> c;
      --a, --b;
      graph[a].push_back({b, c}), graph[b].push_back({a, c});
    }

    vector<vector<I>> children(n);
    vector<I> minimize(n);
    minimize[k] = inf;
    {
      vector<bool> visited(n, false);
      visited[k] = true;
      vector<I> dfs = {k};
      while (!dfs.empty()) {
        I i = dfs.back();
        dfs.pop_back();

        for (II j : graph[i]) {
          if (visited[j.first]) continue;
          visited[j.first] = true;

          children[i].push_back(j.first);
          minimize[j.first] = j.second;
          dfs.push_back(j.first);
        }
      }
    }

    vector<bool> is_leaf(n, true);
    is_leaf[k] = false;
    {
      vector<I> dfs = {k};
      while (!dfs.empty()) {
        I i = dfs.back();
        dfs.pop_back();

        for (I j : children[i]) {
          is_leaf[i] = false;
          minimize[j] = min(minimize[j], minimize[i]);
          dfs.push_back(j);
        }
      }
    }

    vector<I> w;
    for (I i = 0; i < n; ++i) {
      if (is_leaf[i]) w.push_back(minimize[i]);
    }

    I m;
    cin >> m;
    vector<I> v(m);
    for (I &i : v) cin >> i;

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    I c = 0;
    I l = 0;
    for (I i : v) {
      while (l < w.size() && w[l] < i) ++l;
      if (l >= w.size()) break;
      ++c, ++l;
    }
    cout << c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

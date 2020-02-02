#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<I>> graph(n);
  vector<II> extra;
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    if (i < n - 1)
      graph[a].push_back(b), graph[b].push_back(a);
    else
      extra.push_back({a, b});
  }

  vector<vector<I>> tree(n);
  vector<I> depth(n), lo(n), hi(n);

  {
    vector<bool> visited(n);
    I k = 0;
    function<void(I)> dfs = [&](I i) {
      lo[i] = hi[i] = k++;
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        tree[i].push_back(j);
        depth[j] = depth[i] + 1;
        dfs(j);
        hi[i] = hi[j];
      }
    };
    visited[0] = true, dfs(0);
  }

  vector<I> inc(n);
  for (auto [a, b] : extra) {
    if (depth[a] < depth[b]) swap(a, b);
    if (lo[b] <= lo[a] && lo[a] <= hi[b]) {
      // Nie jestem pewien czy ta pętla nie powinna sprawiać, że w najgorszym
      // przypadku rozwiązanie jest kwadratowe, ale wchodzi. Można napisać
      // binary searcha i będzie O(n log n).
      I c = -1;
      for (I i : tree[b])
        if (lo[a] <= hi[i]) {
          c = i;
          break;
        }

      ++inc[c], --inc[a];
    } else
      ++inc[0], --inc[a], --inc[b];
  }

  vector<I> acc(n);
  {
    function<void(I)> dfs = [&](I i) {
      acc[i] += inc[i];
      for (I j : tree[i]) acc[j] += acc[i], dfs(j);
    };
    dfs(0);
  }

  vector<I> r;
  for (I i = 0; i < n; ++i) {
    if (acc[i] == 0) r.push_back(i);
  }
  if (r.empty()) {
    cout << "NIE\n";
  } else {
    cout << "TAK\n";
    for (I i : r) cout << i + 1 << " ";
    cout << "\n";
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

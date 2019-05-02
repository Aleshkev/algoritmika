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
    vector<I> q = {0};
    visited[0] = true;
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        tree[i].push_back(j);
        q.push_back(j);
      }
    }
  }

  vector<I> oneway(n), twoway(n);
  auto val = [&](I i) { return max((I)tree[i].size(), oneway[i]); };
  function<void(I)> dfs = [&](I i) {
    if (tree[i].empty()) {
      oneway[i] = twoway[i] = -1;
      return;
    }

    for (I j : tree[i]) {
      dfs(j);
    }
    sort(tree[i].begin(), tree[i].end(),
         [&](I x, I y) { return val(x) > val(y); });
    oneway[i] = val(tree[i][0]) + tree[i].size() - 1;

    twoway[i] = val(tree[i][0]) - 1 +
                (tree[i].size() > 1 ? max(val(tree[i][1]) - 1, (I)0) : 0) +
                tree[i].size() + (i != 0 ? 1 : 0);
  };
  dfs(0);

  cout << *max_element(twoway.begin(), twoway.end()) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

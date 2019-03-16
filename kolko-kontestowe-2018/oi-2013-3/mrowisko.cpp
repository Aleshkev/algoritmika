#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m, k;
  cin >> n >> m >> k;

  vector<I> groups(m);
  for (I &i : groups) cin >> i;
  sort(groups.begin(), groups.end());

  vector<vector<I>> graph(n);

  I root_a, root_b;
  cin >> root_a >> root_b;
  --root_a, --root_b;

  for (I i = 1; i < n - 1; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<vector<I>> children(n);
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
    visited[root_a] = visited[root_b] = true;
    dfs(root_a), dfs(root_b);
  }

  vector<I> multiplier(n);
  {
    function<void(I)> dfs = [&](I i) {
      for (I j : children[i]) {
        multiplier[j] = multiplier[i] * children[i].size();
        if (multiplier[j] > inf) multiplier[j] = inf;
        dfs(j);
      }
    };

    multiplier[root_a] = multiplier[root_b] = 1;
    dfs(root_a), dfs(root_b);
  }

  vector<I> divisors;
  for (I i = 0; i < n; ++i) {
    if (children[i].size() > 0) continue;
    divisors.push_back(multiplier[i]);
  }

  I c = 0;
  for (I x : divisors) {
    c += upper_bound(groups.begin(), groups.end(),
                     (x == 1 ? x * k : x * (k + 1) - 1)) -
         lower_bound(groups.begin(), groups.end(), x * k);
  }
  cout << c * k << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
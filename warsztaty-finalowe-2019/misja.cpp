#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, budget;
  cin >> n >> budget;

  vector<I> parent(n), cost(n), multiplier(n);
  vector<vector<I>> children(n);

  for (I i = 0; i < n; ++i) {
    cin >> parent[i] >> cost[i] >> multiplier[i];
    --parent[i];
    if (i != 0) children[parent[i]].push_back(i);
  }
  vector<I> population(n);
  {
    function<void(I)> dfs = [&](I i) {
      ++population[i];
      for (I j : children[i]) {
        dfs(j);
        population[i] += population[j];
      }
      sort(children[i].begin(), children[i].end(),
           [&](I a, I b) { return population[a] > population[b]; });
    };
    dfs(0);
  }

  I quick_ans = 0;

  function<void(I, multiset<I> &, I &)> dfs = [&](I i, multiset<I> &p, I &c) {
    if (!children[i].empty()) {
      dfs(children[i][0], p, c);
      for (I j : children[i]) {
        if (j == children[i][0]) continue;
        multiset<I> s;
        I z = 0;
        dfs(j, s, z);
        for (I k : s) p.insert(k);
        c += z;
      }
    }
    p.insert(cost[i]);
    c += cost[i];

    while (c > budget) {
      auto biggest = prev(p.end());
      c -= *biggest;
      p.erase(biggest);
    }

    quick_ans = max<I>(quick_ans, multiplier[i] * p.size());
  };

  multiset<I> stalin;
  I hitler = 0;
  dfs(0, stalin, hitler);
  cout << quick_ans << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

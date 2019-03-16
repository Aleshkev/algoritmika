#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> cost(n);
  for (I &i : cost) cin >> i;

  vector<vector<I>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  I min_c = accumulate(cost.begin(), cost.end(), 0);
  for (I b = 0; b < (1 << n); ++b) {
    I c = 0;
    for (I i = 0; i < n; ++i) {
      if (b & (1 << i)) c += cost[i];
    }
    if (c > min_c) continue;

    bool ok = true;
    for (I i = 0; i < n; ++i) {
      if (b & (1 << i)) continue;
      bool this_ok = false;
      for (I j : graph[i]) {
        if (b & (1 << j)) {
          this_ok = true;
          break;
        }
      }
      if (!this_ok) {
        ok = false;
        break;
      }
    }
    if (ok) {
      min_c = min(min_c, c);
    }
  }
  cout << min_c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
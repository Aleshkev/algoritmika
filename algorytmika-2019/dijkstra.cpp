#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<II>> graph(n);
  while (m--) {
    I a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    graph[b].push_back({a, w});
  }

  vector<I> d(n, inf);

  priority_queue<II, vector<II>, greater<II>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto [x, i] = q.top();
    q.pop();
    if (x >= d[i]) continue;
    d[i] = x;

    for (auto [j, dx] : graph[i]) {
      if (d[j] == inf) q.push({x + dx, j});
    }
  }

  for (I i = 0; i < n; ++i) {
    if (d[i] < inf)
      cout << d[i] << "\n";
    else
      cout << "+oo\n";  // Tfu.
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

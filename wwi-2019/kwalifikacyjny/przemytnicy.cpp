#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

struct E {
  I v, w;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<E>> graph(2 * n);
  for (I i = 0; i < n; ++i) {
    I p;
    cin >> p;
    graph[i].push_back({n + i, p / 2});
  }

  I m;
  cin >> m;
  for (I i = 0; i < m; ++i) {
    I a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    graph[a].push_back({b, c});
    graph[n + a].push_back({n + b, c});
  }

  vector<I> d(2 * n, inf);
  priority_queue<II, vector<II>, greater<II>> q;
  d[0] = 0, q.push({d[0], 0});

  while (!q.empty()) {
    I u = q.top().second;
    q.pop();
    for (E e : graph[u]) {
      I v = e.v, w = e.w;
      if (d[v] <= d[u] + w) continue;
      d[v] = d[u] + w;
      q.push({d[v], v});
    }
  }

  cout << d[n] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

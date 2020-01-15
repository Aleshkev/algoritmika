#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef double F;
constexpr F inf = 1e18;

struct E {
  I a, b;
  F w;
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<E> g_edges(m);
  for (I i = 0; i < m; ++i) {
    cin >> g_edges[i].a >> g_edges[i].b >> g_edges[i].w;
    --g_edges[i].a, --g_edges[i].b;
  }

  for (I i = 0; i < n; ++i) {
    g_edges.push_back({n, i, 0});
  }
  m = g_edges.size();

  auto is_ok = [&](F k) {
    auto edges = g_edges;
    for (E &e : edges) e.w = k - e.w;

    vector<F> d(n + 1, inf);
    d[n] = 0;
    for (I it = 0; it < n; ++it)
      for (E e : edges)
        if (d[e.a] + e.w < d[e.b]) d[e.b] = d[e.a] + e.w;
    auto t = d;
    for (E e : edges)
      if (t[e.a] + e.w < t[e.b]) t[e.b] = t[e.a] + e.w;

    return t != d;
  };

  F lo = 0, hi = 1e10;
  while (abs(lo - hi) > 0.0001) {
    F mid = (lo + hi) / 2;
    if (is_ok(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << fixed << setprecision(3) << lo << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

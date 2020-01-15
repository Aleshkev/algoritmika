#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;

struct E {
  I a, b, v;
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m, q;
  cin >> n >> m >> q;

  vector<E> edges(m);
  for (I i = 0; i < m; ++i) {
    cin >> edges[i].a >> edges[i].b >> edges[i].v;
    --edges[i].a, --edges[i].b;
  }

  while (q--) {
    I a, b;
    cin >> a >> b;
    --a, --b;

    vector<I> d(n, 2 * inf), from(n, -1);
    d[a] = 0;

    for (I it = 0; it < n - 1; ++it) {
      for (E e : edges) {
        if (d[e.a] + e.v < d[e.b]) {
          d[e.b] = d[e.a] + e.v;
          from[e.b] = e.a;
        }
      }
    }

    if (d[b] < inf) {
      vector<I> p;
      for (I x = b; x != -1; x = from[x]) {
        p.push_back(x);
      }
      reverse(p.begin(), p.end());

      cout << d[b] << " " << p.size() << " ";
      for (I i : p) cout << i + 1 << " ";
      cout << "\n";
    } else {
      cout << "NIE\n";
    }
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

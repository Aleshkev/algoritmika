#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct E {
  I a, b, l;
};

struct union_set {
  vector<I> parent;
  union_set(I n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
  }
  I root(I x) {
    if (parent[x] != x) {
      parent[x] = root(parent[x]);
    }
    return parent[x];
  }
  bool unite(I a, I b) {
    I root_a = root(a), root_b = root(b);

    if (root_a == root_b) return false;

    parent[root_b] = root_a;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<E> edges(m);
  for (E &e : edges) {
    cin >> e.a >> e.b >> e.l;
    --e.a, --e.b;
    if (e.a > e.b) swap(e.a, e.b);
  }
  sort(edges.begin(), edges.end(), [](const E &l, const E &r) {
    return tie(l.l, l.a, l.b) < tie(r.l, r.a, r.b);
  });

  I q;
  cin >> q;
  while (q--) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    if (a > b) swap(a, b);

    I c = 0;
    union_set v(n);

    for (E &e : edges) {
      if (e.a == a && e.b == b) {
        v.unite(e.a, e.b);
        c += e.l;
        break;
      }
    }

    for (E &e : edges) {
      if (e.a == a && e.b == b) continue;
      if (v.unite(e.a, e.b)) {
        c += e.l;
      }
    }
    cout << c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

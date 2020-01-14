#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;

struct P {
  I a, c;
};
P combine(P x, P y) {
  if (x.a == y.a)
    return {x.a, x.c + y.c};
  else if (x.a < y.a)
    return {x.a, x.c};
  else
    return {y.a, y.c};
};

struct tree_t {
  vector<P> v;
  I n, w;
  tree_t(I n) : n(n), w(1 << __lg(2 * n)) { v.assign(2 * w, {inf, 1}); }
  void set(I i, I x) {
    i += w;
    v[i].a = x;
    for (i /= 2; i > 0; i /= 2) {
      v[i] = combine(v[2 * i], v[2 * i + 1]);
    }
  }
  P get(I i, I j) {
    if (i == j) return v[w + i];
    i += w, j += w;
    P c = combine(v[i], v[j]);
    for (; i / 2 != j / 2; i /= 2, j /= 2) {
      if (i % 2 == 0) c = combine(c, v[i + 1]);
      if (j % 2 == 1) c = combine(c, v[j - 1]);
    }
    return c;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, q;
  cin >> n >> q;

  tree_t tree(n);

  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.set(i, x);
  }

  for (I i = 0; i < q; ++i) {
    char o;
    cin >> o;
    I a, b;
    cin >> a >> b;
    if (o == '=') {
      --a;
      tree.set(a, b);
    } else {
      --a, --b;
      auto p = tree.get(a, b);
      cout << p.a << " " << p.c << "\n";
    }
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

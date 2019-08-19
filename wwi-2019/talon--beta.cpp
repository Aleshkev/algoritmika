//
// Zrobiłem to bez żadnej kartki ani długopisu, powinna być za to specjalna
// nagroda.
//

#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

struct pt {
  I x, y;
};

template <typename T>
struct point_tree {
  I n, w;
  vector<I> v;
  point_tree(I n) : n(n), w(1 << __lg(2 * n - 1)) { v.resize(2 * w); }
  point_tree(const vector<T> &initial) {
    point_tree(initial.size());
    for (I i = 0; i < n; ++i) v[w + i] = initial[i];
    for (I i = w - 1; i > 0; --i) v[i] = max(v[2 * i], v[2 * i + 1]);
  }
  void set(I i, T x) {
    for (i += w, v[i] = max(v[i], x), i /= 2; i > 0; i /= 2)
      v[i] = max(v[2 * i], v[2 * i + 1]);
  }
  T get(I i) { return v[w + i]; }
  T get(I i, I j) {
    if (i == j) return get(i);
    i += w, j += w;
    T c = max(v[i], v[j]);
    for (; i / 2 != j / 2; i /= 2, j /= 2) {
      if (i % 2 == 0) c = max(c, v[i + 1]);
      if (j % 2 == 1) c = max(c, v[j - 1]);
    }
    return c;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<pt> v(n);
  for (pt &i : v) cin >> i.x >> i.y;

  sort(v.begin(), v.end(), [&](const pt &l, const pt &r) {
    return make_pair(l.x + l.y, l.x) < make_pair(r.x + r.y, r.x);
  });

  // Skalujemy jak papieża.
  vector<I> ys(n);
  for (const pt &i : v) ys.push_back(i.y);
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  for (pt &i : v) i.y = lower_bound(ys.begin(), ys.end(), i.y) - ys.begin();

  point_tree<I> tree(ys.size());
  vector<I> w(n);
  for (I i = 0; i < n; ++i) {
    w[i] = 1 + tree.get(v[i].y, ys.size() - 1);
    tree.set(v[i].y, w[i]);
  }

  cout << tree.v[1] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

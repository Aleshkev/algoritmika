#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;
const I inf = 2e9;

// Drzewo przedziałowe (+, max), z operacją index(x).
struct segment_tree {
  I n, w;
  vector<I> v, d;
  segment_tree(I n) : n(n) {
    for (w = 1; w < n;) w *= 2;
    v.resize(2 * w);
    d.resize(2 * w);
  }

  void push(I i) {
    for (I k = 0; k < 2; ++k) v[2 * i + k] += d[i], d[2 * i + k] += d[i];
    d[i] = 0;
  }

  I query(I qb, I qe, I rb, I re, I i, I x) {
    if (qb > re || qe < rb) return 0;
    if (qb <= rb && re <= qe) {
      v[i] += x, d[i] += x;
      return v[i];
    }
    push(i);
    I mid = (rb + re) / 2;
    I r = query(qb, qe, rb, mid, 2 * i, x) +
          query(qb, qe, mid + 1, re, 2 * i + 1, x);
    v[i] = max(v[2 * i], v[2 * i + 1]);
    return r;
  }
  I add(I qb, I qe, I x) { return query(qb, qe, 0, w - 1, 1, x); }
  I get(I qb, I qe) { return query(qb, qe, 0, w - 1, 1, 0); }
  I get(I q) { return query(q, q, 0, w - 1, 1, 0); }

  I index(I x) {
    I i = 1;
    while (i < w) {
      push(i);
      if (x <= v[2 * i]) {
        i = 2 * i;
      } else {
        i = 2 * i + 1;
      }
    }
    return i - w;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> v(n);
  for (I &i : v) cin >> i;
  sort(v.begin(), v.end());
  segment_tree tree(n + 1);
  for (I i = 0; i < n; ++i) {
    tree.add(i, i, v[i]);
  }
  tree.add(n, n, inf);

  while (m--) {
    string o;
    cin >> o;

    if (o[0] == 'p') {
      I x;
      cin >> x;
      --x;

      I a = tree.get(x);
      if (x + 1 < n && a == tree.get(x + 1)) {
        I y = tree.index(a), z = tree.index(a + 1) - 1, l = x - y + 1;
        if (y > 0) tree.add(0, y - 1, +1);
        tree.add(z - l + 1, z, +1);
      } else {
        tree.add(0, x, +1);
      }
    } else {
      I a, b;
      cin >> a >> b;
      cout << tree.index(b + 1) - tree.index(a) << "\n";
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

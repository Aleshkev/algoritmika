#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
const I inf = 1e18;

struct tree {
  vector<I> v, d;
  I w;
  tree(I n) : w(1 << __lg(2 * n - 1)) {
    v.assign(2 * w, -inf), d.assign(2 * w, 0);
  }
  void push(I i) {
    v[2 * i] += d[i], v[2 * i + 1] += d[i];
    d[2 * i] += d[i], d[2 * i + 1] += d[i];
    d[i] = 0;
  }
  void add(I qb, I qe, I i, I rb, I re, I x) {
    if (qb > re || qe < rb) return;
    if (qb <= rb && re <= qe) {
      v[i] += x, d[i] += x;
      return;
    }
    push(i);
    I mid = (rb + re) / 2;
    add(qb, qe, 2 * i, rb, mid, x);
    add(qb, qe, 2 * i + 1, mid + 1, re, x);
    v[i] = max(v[2 * i], v[2 * i + 1]);
  }
  void add(I qb, I qe, I x) { add(qb, qe, 1, 0, w - 1, x); }

  I get_max() {
    I i = 1;
    while (i < w) {
      push(i);
      if (v[2 * i] >= v[2 * i + 1])
        i = 2 * i;
      else
        i = 2 * i + 1;
    }
    return i - w;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;
  tree t(n);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    t.add(i, i, inf - x);
  }

  vector<I> r(n, -1);

  for (I i = 0; i < m; ++i) {
    I p, k, x;
    cin >> p >> k >> x;
    --p, --k;
    t.add(p, k, x);

    while (t.v[1] >= 0) {
      I w = t.v[1], j = t.get_max();
      r[j] = i;
      t.add(j, j, -inf);
    }
  }

  for (I i : r) {
    if (i == -1)
      cout << "NIE\n";
    else
      cout << i + 1 << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

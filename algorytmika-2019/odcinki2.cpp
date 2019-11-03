#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

struct pkx {
  I p, k, x;
};
pkx operator*(const pkx &a, const pkx &b) {
  return {a.p + b.p, a.k + b.k, a.x + b.x + a.p * b.k};
}

struct point_tree {
  vector<pkx> v;
  I w;
  point_tree(I n) : w(1 << __lg(n) << 1) { v.resize(2 * w); }
  void set(bool is_k, I i) {
    i += w;

    if (is_k)
      v[i].p = 0, v[i].k = 1;
    else
      v[i].p = 1, v[i].k = 0;
    for (i /= 2; i > 0; i /= 2) {
      v[i] = v[2 * i] * v[2 * i + 1];
    }
  }
  pkx get(I qb, I qe, I i, I rb, I re) {
    if (qb > re || qe < rb) return {0, 0, 0};
    if (qb <= rb && re <= qe) return v[i];
    I mid = (rb + re) / 2;
    return get(qb, qe, 2 * i, rb, mid) * get(qb, qe, 2 * i + 1, mid + 1, re);
  }
  pkx get(I qb, I qe) { return get(qb, qe, 1, 0, w - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;
  point_tree tree(n);
  string s;
  cin >> s;
  for (I i = 0; i < n; ++i) {
    tree.set((s[i] == 'K'), i);
  }

  while (m--) {
    char o;
    cin >> o;
    if (o == '?') {
      I a, b;
      cin >> a >> b;
      --a, --b;
      cout << tree.get(a, b).x << "\n";
    } else {
      I i;
      cin >> i;
      --i;
      tree.set(!tree.v[tree.w + i].k, i);
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

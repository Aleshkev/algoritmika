#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
const I inf = 1e9;

struct Tree {
  I w;
  vector<I> value, for_later;
  Tree(I n) {
    for (w = 1; w < n;) w *= 2;
    value.assign(2 * w, 0);
    for_later.assign(2 * w, 0);
  }

  I query(I qb, I qe, I rb, I re, I i, I x = 0) {
    if (re < qb || rb > qe) return inf;
    if (qb <= rb && re <= qe) {
      value[i] += x;
      for_later[i] += x;
      return value[i];
    }

    value[2 * i] += for_later[i];
    for_later[2 * i] += for_later[i];

    value[2 * i + 1] += for_later[i];
    for_later[2 * i + 1] += for_later[i];

    for_later[i] = 0;

    I mid = (rb + re) / 2;

    I r = min(query(qb, qe, rb, mid, 2 * i, x),
              query(qb, qe, mid + 1, re, 2 * i + 1, x));

    value[i] = min(value[2 * i], value[2 * i + 1]);
    return r;
  }
  I query(I qb, I qe, I x = 0) { return query(qb, qe, 0, w - 1, 1, x); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> values(n);

  Tree tree(n);
  for (I i = 0; i < n; ++i) {
    cin >> values[i];
    tree.query(i, n - 1, values[i]);
  }

  for (;;) {
    I p;
    cin >> p;
    if (p == -1) break;
    if (p == 0) {
      bool ok = (tree.query(0, n - 1) >= 0 && tree.query(n - 1, n - 1) == 0);
      cout << (ok ? "TAK" : "NIE") << '\n';
    } else {
      --p;
      tree.query(p, n - 1, -values[p] * 2);
      values[p] *= -1;
    }
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

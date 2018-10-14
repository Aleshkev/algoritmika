#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

struct Tree {
  I w;
  vector<I> data, leftover;
  Tree(I n) {
    for (w = 1; w < n;) w *= 2;
    data.assign(2 * w, 0);
    leftover.assign(2 * w, 0);
  }

  I query(I qb, I qe, I rb, I re, I i, I x = 0) {
    if (re < qb || rb > qe) return inf;
    if (qb <= rb && re <= qe) {
      data[i] += x;
      leftover[i] += x;
      return data[i];
    }

    I mid = (rb + re) / 2;

    data[2 * i] += leftover[i];
    data[2 * i + 1] += leftover[i];
    leftover[i] = 0;

    I r = min(query(qb, qe, rb, mid, 2 * i, x),
              query(qb, qe, mid + 1, re, 2 * i + 1, x));

    data[i] = min(data[2 * i], data[2 * i + 1]);

    return r;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  Tree t(20);

  for (;;) {
    char a;
    I b, c;
    cin >> a >> b >> c;
    if (a == '+') {
      I d;
      cin >> d;
      t.query(b, c, 0, t.w - 1, 1, d);
    } else {
      cout << t.query(b, c, 0, t.w - 1, 1) << endl;
    }
    for (I i = 0; i <= 20; ++i) cout << t.query(i, i, 0, t.w - 1, 1) << ' ';
    cout << endl;
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

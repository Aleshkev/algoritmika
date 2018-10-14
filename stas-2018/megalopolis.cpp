#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

struct Tree {
  vector<I> value, for_later;
  I w;
  Tree(I n) {
    for (w = 1; w < n;) w *= 2;
    value.assign(2 * w, 0);
    for_later.assign(2 * w, 0);
  }
  I query(I qb, I qe, I rb, I re, I i, I x) {
    if (re < qb || qe < rb) return 0;
    if (qb <= rb && re <= qe) {
      value[i] += x;
      for_later[i] += x;
      return value[i];
    }

    value[2 * i] += for_later[i];
    value[2 * i + 1] += for_later[i];

    for_later[2 * i] += for_later[i];
    for_later[2 * i + 1] += for_later[i];

    for_later[i] = 0;

    I mid = (rb + re) / 2;
    I r = query(qb, qe, rb, mid, 2 * i, x) +
          query(qb, qe, mid + 1, re, 2 * i + 1, x);
    value[i] = value[2 * i] + value[2 * i + 1];
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

  vector<vector<I>> children(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    children[a].push_back(b);
  }

  vector<I> rb(n), re(n);
  {
    I id = 0;
    function<I(I)> dfs = [&](I i) {
      re[i] = rb[i] = id++;
      // cout << "visiting " << i << endl;

      for (I j : children[i]) {
        re[i] = max(re[i], dfs(j));
      }

      return re[i];
    };
    dfs(0);
  }

  Tree tree(n);
  for (I i = 0; i < n; ++i) {
    tree.query(rb[i], re[i], 1);
  }

  I m;
  cin >> m;

  for (I i = 0; i < n + m - 1; ++i) {
    char c;
    cin >> c;
    if (c == 'A') {
      I a, b;  // a is the parent of b.
      cin >> a >> b;
      --a, --b;
      tree.query(rb[b], re[b], -1);
    } else if (c == 'W') {
      I a;
      cin >> a;
      --a;
      cout << tree.query(rb[a], rb[a]) - 1 << '\n';
    }
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

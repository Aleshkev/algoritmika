#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

// For testing.
struct fake_tree {
  vector<I> data;
  fake_tree(I n) { data.assign(n, 0); }
  void set(I qb, I qe, I x) {
    for (I i = qb; i <= qe; ++i) {
      data[i] = x;
    }
  }
  I get(I qb, I qe) {
    I c = 0;
    for (I i = qb; i <= qe; ++i) {
      c ^= data[i];
    }
    return c;
  }
};

struct real_tree {
  I w, current_time = 1;
  vector<I> value, for_later;
  vector<bool> active;
  real_tree(I n) {
    for (w = 1; w < n; w *= 2)
      ;
    value.assign(2 * w, 0);
    for_later.assign(2 * w, 0);
    active.assign(2 * w, false);
  }

  I get(I qb, I qe, I rb, I re, I i) {
    if (qe < rb || qb > re) return 0;
    if (qb <= rb && re <= qe) {
      return value[i];
    }

    I mi = (rb + re) / 2;
    if (active[i]) {
      value[2 * i] = for_later[i] * (rb == mi);
      for_later[2 * i] = for_later[i];
      active[2 * i] = true;

      value[2 * i + 1] = for_later[i] * (mi + 1 == re);
      for_later[2 * i + 1] = for_later[i];
      active[2 * i + 1] = true;

      for_later[i] = 0;
      active[i] = false;
    }

    return get(qb, qe, rb, mi, 2 * i) ^ get(qb, qe, mi + 1, re, 2 * i + 1);
  }
  I get(I qb, I qe) { return get(qb, qe, 0, w - 1, 1); }

  void set(I qb, I qe, I rb, I re, I i, I x) {
    if (qe < rb || qb > re) {
      return;
    }
    if (qb <= rb && re <= qe) {
      value[i] = x * (rb == re);
      for_later[i] = x;
      active[i] = true;
      return;
    }

    I mi = (rb + re) / 2;
    if (active[i]) {
      value[2 * i] = for_later[i] * (rb == mi);
      for_later[2 * i] = for_later[i];
      active[2 * i] = true;

      value[2 * i + 1] = for_later[i] * (mi + 1 == re);
      for_later[2 * i + 1] = for_later[i];
      active[2 * i + 1] = true;

      for_later[i] = 0;
      active[i] = false;
    }

    set(qb, qe, rb, mi, 2 * i, x);
    set(qb, qe, mi + 1, re, 2 * i + 1, x);
    value[i] = (value[2 * i] ^ value[2 * i + 1]);
  }
  void set(I qb, I qe, I x) { set(qb, qe, 0, w - 1, 1, x); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  real_tree tree(n);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.set(i, i, x);
  }

  for (I i = 0; i < m; ++i) {
    I action, b, e;
    cin >> action >> b >> e;
    --b, --e;
    if (action == 0) {
      I h;
      cin >> h;
      tree.set(b, e, h);
    } else {
      cout << tree.get(b, e) << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

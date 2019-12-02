#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;

struct Add {
  I neutral = 0;
  I operator()(I a, I b) { return a + b; }
};

struct Min {
  I neutral = inf;
  I operator()(I a, I b) { return min(a, b); }
};

template <typename T, class Update, class Combine>
struct segment_tree {
  Update update;
  Combine combine;
  I n, w;
  vector<T> v, d;
  segment_tree(I n, T x = T()) : n(n), w(1 << __lg(2 * n - 1)) {
    v.assign(2 * w, x), d.assign(2 * w, update.neutral);
  }
  segment_tree(const vector<T> &initial) {
    segment_tree(initial.size());
    for (I i = 0; i < n; ++i) v[w + i] = initial[i];
    for (I i = w - 1; i > 0; --i) v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  void push(I i) {
    for (I k = 0; k < 2; ++k) {
      v[2 * i + k] = update(v[2 * i + k], d[i]);
      d[2 * i + k] = update(d[2 * i + k], d[i]);
    }
    d[i] = update.neutral;
  }
  void change(I qb, I qe, I rb, I re, I i, T x) {
    if (qb > re || qe < rb) {
      return;
    } else if (qb <= rb && re <= qe) {
      v[i] = update(v[i], x);
      d[i] = update(d[i], x);
    } else {
      push(i);
      change(qb, qe, rb, (rb + re) / 2, 2 * i, x);
      change(qb, qe, (rb + re) / 2 + 1, re, 2 * i + 1, x);
      v[i] = combine(v[2 * i], v[2 * i + 1]);
    }
  }
  T get(I qb, I qe, I rb, I re, I i, I d = 0) {
    if (qb > re || qe < rb) {
      return combine.neutral;
    } else if (qb <= rb && re <= qe) {
      return v[i];
    } else {
      push(i);
      I x = combine(get(qb, qe, rb, (rb + re) / 2, 2 * i, d + 1),
                    get(qb, qe, (rb + re) / 2 + 1, re, 2 * i + 1, d + 1));
      return x;
    }
  }
  void change(I i, I j, T x) { change(i, j, 0, w - 1, 1, x); }
  T get(I i, I j) { return get(i, j, 0, w - 1, 1); }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, q;
  cin >> n >> q;

  segment_tree<I, Add, Min> tree(n);

  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.change(i, i, x);
  }

  while (q--) {
    char o;
    I a, b;
    cin >> o >> a >> b;
    --a, --b;
    if (o == '+') {
      I x;
      cin >> x;
      tree.change(a, b, x);
    } else {
      cout << tree.get(a, b) << "\n";
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}

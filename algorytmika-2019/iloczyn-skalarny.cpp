#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;

struct delta {
  I a, b;
};
struct trio {
  I a, b, x;
};

struct Update {
  delta neutral{0, 0};
  delta add(delta u, delta v) { return {u.a + v.a, u.b + v.b}; }
  trio apply(trio u, delta d, I l) {
    return {u.a + d.a * l, u.b + d.b * l,
            u.x + u.a * d.b + u.b * d.a + d.a * d.b * l};
  }
};
struct Combine {
  trio neutral{0, 0, 0};
  trio operator()(trio u, trio v) {  //
    return {u.a + v.a, u.b + v.b, u.x + v.x};
  }
};

template <class Update, class Combine>
struct segment_tree {
  Update update;
  Combine combine;
  I n, w;
  using V = decltype(Combine::neutral);
  using D = decltype(Update::neutral);
  vector<V> v;
  vector<D> d;
  vector<I> l;
  segment_tree(I n, V x = V()) : n(n), w(1 << __lg(2 * n - 1)) {
    v.assign(2 * w, x), d.assign(2 * w, update.neutral);
    l.assign(2 * w, 1);
    for (I i = w - 1; i > 0; --i) l[i] = 2 * l[2 * i];
  }
  segment_tree(const vector<V> &initial) : segment_tree(initial.size()) {
    for (I i = 0; i < n; ++i) v[w + i] = initial[i];
    for (I i = w - 1; i > 0; --i) v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  void push(I i) {
    for (I k = 0; k < 2; ++k) {
      v[2 * i + k] = update.apply(v[2 * i + k], d[i], l[2 * i + k]);
      d[2 * i + k] = update.add(d[2 * i + k], d[i]);
    }
    d[i] = update.neutral;
  }
  void change(I qb, I qe, I rb, I re, I i, D x) {
    if (qb > re || qe < rb) {
      return;
    } else if (qb <= rb && re <= qe) {
      v[i] = update.apply(v[i], x, l[i]);
      d[i] = update.add(d[i], x);
    } else {
      push(i);
      change(qb, qe, rb, (rb + re) / 2, 2 * i, x);
      change(qb, qe, (rb + re) / 2 + 1, re, 2 * i + 1, x);
      v[i] = combine(v[2 * i], v[2 * i + 1]);
    }
  }
  V get(I qb, I qe, I rb, I re, I i) {
    if (qb > re || qe < rb) {
      return combine.neutral;
    } else if (qb <= rb && re <= qe) {
      return v[i];
    } else {
      push(i);
      return combine(get(qb, qe, rb, (rb + re) / 2, 2 * i),
                     get(qb, qe, (rb + re) / 2 + 1, re, 2 * i + 1));
    }
  }
  void change(I i, I j, D x) { change(i, j, 0, w - 1, 1, x); }
  V get(I i, I j) { return get(i, j, 0, w - 1, 1); }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, q;
  cin >> n >> q;

  segment_tree<Update, Combine> tree(n);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.change(i, i, {x, 0});
  }
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.change(i, i, {0, x});
  }

  while (q--) {
    char o;
    cin >> o;
    if (o == '?') {
      I a, b;
      cin >> a >> b;
      --a, --b;
      cout << tree.get(a, b).x << "\n";
    } else if (o == '+') {
      char z;
      I a, b, x;
      cin >> z >> a >> b >> x;
      --a, --b;
      if (z == 'a')
        tree.change(a, b, {x, 0});
      else
        tree.change(a, b, {0, x});
    }
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

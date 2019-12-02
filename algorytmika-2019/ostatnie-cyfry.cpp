#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;

typedef array<I, 10> cell_t;
constexpr cell_t zero_cell = {};

struct UpdateCell {
  I neutral = 0;
  cell_t apply(cell_t a, I x) {
    cell_t r;
    for (I i = 0; i < a.size(); ++i) {
      r[(i + x) % 10] = a[i];
    }
    return r;
  }
  I add(I a, I b) { return (a + b) % 10; }
};

struct CombineCells {
  cell_t neutral = zero_cell;
  cell_t operator()(cell_t a, cell_t b) {
    cell_t r;
    for (I i = 0; i < a.size(); ++i) r[i] = a[i] + b[i];
    return r;
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
  segment_tree(I n, V x = V()) : n(n), w(1 << __lg(2 * n - 1)) {
    v.assign(2 * w, x), d.assign(2 * w, update.neutral);
  }
  segment_tree(const vector<V> &initial) : segment_tree(initial.size()) {
    for (I i = 0; i < n; ++i) v[w + i] = initial[i];
    for (I i = w - 1; i > 0; --i) v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  void push(I i) {
    for (I k = 0; k < 2; ++k) {
      v[2 * i + k] = update.apply(v[2 * i + k], d[i]);
      d[2 * i + k] = update.add(d[2 * i + k], d[i]);
    }
    d[i] = update.neutral;
  }
  void change(I qb, I qe, I rb, I re, I i, D x) {
    if (qb > re || qe < rb) {
      return;
    } else if (qb <= rb && re <= qe) {
      v[i] = update.apply(v[i], x);
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

template <class U, class V>
ostream &operator<<(ostream &o, segment_tree<U, V> &v) {
  o << "{";
  for (I i = 0; i < v.n; ++i) {
    o << v.get(i, i);
    if (i < v.n - 1) o << ", ";
  }
  o << "}";
  return o;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, q;
  cin >> n >> q;

  vector<cell_t> initial(n, zero_cell);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    x %= 10;
    initial[i][x] = 1;
  }

  segment_tree<UpdateCell, CombineCells> tree(initial);

  while (q--) {
    char o;
    I a, b;
    cin >> o >> a >> b;
    --a, --b;
    if (o == '?') {
      auto c = tree.get(a, b);
      I r = 0;
      for (I i = 0; i < c.size(); ++i) r += i * c[i];
      cout << r << "\n";
    } else {
      I x;
      cin >> x;
      tree.change(a, b, x);
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

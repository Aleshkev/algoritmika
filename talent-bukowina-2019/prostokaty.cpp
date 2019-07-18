#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
const I inf = 2e9;

struct Rectangle {
  I x_1, y_1, x_2, y_2;  // Zawsze x_1 ≤ x_2, y_1 ≤ y_2.

  I area() { return (x_2 - x_1) * (y_2 - y_1); }
};
const Rectangle infinity_rectangle = {-inf, -inf, +inf, +inf};

Rectangle clamp(const Rectangle &a, const Rectangle &b) {
  Rectangle r = {max(a.x_1, b.x_1), max(a.y_1, b.y_1),  //
                 min(a.x_2, b.x_2), min(a.y_2, b.y_2)};
  r.x_2 = max(r.x_1, r.x_2), r.y_2 = max(r.y_1, r.y_2);  // (Pole będzie 0.)
  return r;
}

ostream &operator<<(ostream &o, Rectangle r) {
  o << vector<I>({r.x_1, r.y_1, r.x_2, r.y_2});
  return o;
}

struct Tree {
  vector<Rectangle> data;
  I w;
  Tree(const vector<Rectangle> &v) {
    I n = v.size();
    for (w = 1; w < n;) w <<= 1;
    data.resize(2 * w);
    copy(v.begin(), v.end(), data.begin() + w);

    for (I i = w - 1; i >= 1; --i)
      data[i] = clamp(data[2 * i], data[2 * i + 1]);
  }

  Rectangle get(I qb, I qe, I rb, I re, I i) {
    if (re < qb || rb > qe) return infinity_rectangle;
    if (qb <= rb && re <= qe) return data[i];

    I mid = (rb + re) / 2;
    Rectangle r = clamp(get(qb, qe, rb, mid, 2 * i),  //
                        get(qb, qe, mid + 1, re, 2 * i + 1));
    return r;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, t;
  cin >> n >> t;

  vector<Rectangle> v(n);
  for (auto &i : v) cin >> i.x_1 >> i.y_1 >> i.x_2 >> i.y_2;

  Tree tree(v);

  while (t--) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    // auto r = infinity_rectangle;
    // for (I i = a; i <= b; ++i) {
    //   r = clamp(r, v[i]);
    // }
    // cout << r.area() << '\n';
    auto R = tree.get(a, b, 0, tree.w - 1, 1);
    cout << R.area() << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

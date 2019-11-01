#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

struct point_tree {
  I n, w;
  vector<I> v;
  point_tree(I n) : n(n), w(1 << __lg(2 * n - 1)) { v.assign(2 * w, 0); }
  void set(I i, I x) {
    for (i += w, v[i] = x, i /= 2; i > 0; i /= 2)
      v[i] = max(v[2 * i], v[2 * i + 1]);
  }
  I get(I i) { return v[w + i]; }
  I get(I i, I j) {
    if (i == j) return get(i);
    i += w, j += w;
    I c = max(v[i], v[j]);
    for (; i / 2 != j / 2; i /= 2, j /= 2) {
      if (i % 2 == 0) c = max(c, v[i + 1]);
      if (j % 2 == 1) c = max(c, v[j - 1]);
    }
    return c;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  point_tree t(n);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    t.set(i, x);
  }

  while (m--) {
    char c;
    I a, b;
    cin >> c >> a >> b;
    if (c == '?') {
      --a, --b;
      cout << t.get(a, b) << "\n";
    } else {
      --a;
      t.set(a, t.get(a) + b);
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

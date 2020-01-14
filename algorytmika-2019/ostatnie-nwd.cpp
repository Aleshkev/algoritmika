#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

#define combine __gcd

struct tree_t {
  vector<I> v;
  I n, w;
  tree_t(I n) : n(n), w(1 << __lg(2 * n)) { v.assign(2 * w, 1); }
  void set(I i, I x) {
    i += w;
    v[i] = x;
    for (i /= 2; i > 0; i /= 2) {
      v[i] = combine(v[2 * i], v[2 * i + 1]);
    }
  }
  I get(I i, I j) {
    if (i == j) return v[w + i];
    i += w, j += w;
    auto c = combine(v[i], v[j]);
    for (; i / 2 != j / 2; i /= 2, j /= 2) {
      if (i % 2 == 0) c = combine(c, v[i + 1]);
      if (j % 2 == 1) c = combine(c, v[j - 1]);
    }
    return c;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  tree_t tree(n);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.set(i, x);
  }

  for (I i = 0; i + m <= n; ++i) {
    cout << tree.get(i, i + m - 1) << " ";
  }
  cout << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

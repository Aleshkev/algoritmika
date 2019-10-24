#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

struct point_tree {
  vector<I> v;
  I w;
  point_tree(I n) : w(1 << __lg(n) << 1) { v.assign(2 * w, 0); }
  void set(I i, I x) {
    for (v[i += w] = x, i /= 2; i > 0; i /= 2)
      v[i] = max(v[2 * i], v[2 * i + 1]);
  }
  I all_get() { return v[1]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  point_tree tree(n);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.set(i, x);
  }

  cout << tree.all_get() << "\n";
  while (m--) {
    I i, x;
    cin >> i >> x;
    --i;
    tree.set(i, x);
    cout << tree.all_get() << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

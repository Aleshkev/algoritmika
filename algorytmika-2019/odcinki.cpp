#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

struct point_tree {
  vector<I> p, k, x;
  I w;
  point_tree(I n) : w(1 << __lg(n) << 1) {
    p.assign(2 * w, 0), k.assign(2 * w, 0), x.assign(2 * w, 0);
  }
  void set(bool is_k, I i) {
    i += w;

    if (is_k)
      p[i] = 0, k[i] = 1;
    else
      p[i] = 1, k[i] = 0;
    for (i /= 2; i > 0; i /= 2) {
      p[i] = p[2 * i] + p[2 * i + 1];
      k[i] = k[2 * i] + k[2 * i + 1];
      x[i] = x[2 * i] + x[2 * i + 1] + p[2 * i] * k[2 * i + 1];
    }
  }
  I get_all() { return x[1]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;
  point_tree tree(n);
  string s;
  cin >> s;
  for (I i = 0; i < n; ++i) {
    tree.set((s[i] == 'K'), i);
  }

  cout << tree.get_all() << "\n";
  while (m--) {
    I i;
    cin >> i;
    --i;
    tree.set(!tree.k[tree.w + i], i);
    cout << tree.get_all() << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

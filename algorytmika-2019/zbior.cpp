#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

struct tree {
  vector<I> v;
  I w;
  tree(I n) : w(1 << __lg(n) << 1) { v.assign(2 * w, 0); }
  void add(I i, I x) {
    v[i += w] += x;
    for (i /= 2; i > 0; i /= 2) v[i] = v[i * 2] + v[i * 2 + 1];
  }
  I get_kth(I k) {
    I i = 1;
    while (i < w) {
      if (v[2 * i] >= k)
        i = 2 * i;
      else
        k -= v[2 * i], i = 2 * i + 1;
    }
    return i - w;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I m;
  cin >> m;

  tree t(2e5 + 1);
  while (m--) {
    I op, i;
    cin >> op >> i;
    if (op == 1)
      t.add(i, +1);
    else if (op == 2)
      t.add(i, -1);
    else
      cout << t.get_kth(i) << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

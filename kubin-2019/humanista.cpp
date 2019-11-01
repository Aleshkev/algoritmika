#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

template <typename T>
T lsb(T x) {
  return x & (-x);
}
struct fenwick_tree {
  vector<I> v;
  I n;
  fenwick_tree(I n) : n(n) { v.assign(n + 1, 0); }
  I prefix(I i) {
    I x = 0;
    for (++i; i > 0; i -= lsb(i)) x ^= v[i];
    return x;
  }
  I get(I i, I j) { return prefix(j) ^ prefix(i - 1); }
  I update(I i, I x) {
    for (++i; i <= n; i += lsb(i)) v[i] ^= x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;
  fenwick_tree tree(n);
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    tree.update(i, x);
  }
  for (I i = 0; i < m; ++i) {
    string o;
    I a, b;
    cin >> o >> a >> b;
    --a, --b;
    if (o == "czytaj") {
      cout << tree.get(a, b) << "\n";
    } else {
      I x_a = tree.get(a, a), x_b = tree.get(b, b);
      tree.update(a, x_a ^ x_b);
      tree.update(b, x_a ^ x_b);
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

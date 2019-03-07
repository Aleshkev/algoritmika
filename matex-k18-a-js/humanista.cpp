#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

I lsb(I x) { return x & (-x); }

struct fenwick {
  vector<I> v;
  I n;
  fenwick(I n) : n(n) { v.assign(n + 1, 0); }
  void set(I i, I x) {
    for (++i; i <= n; i += lsb(i)) {
      v[i] ^= x;
    }
  }
  I _get(I i) {
    I c = 0;
    for (++i; i > 0; i -= lsb(i)) {
      c ^= v[i];
    }
    return c;
  }
  I get(I i, I j) { return _get(j) ^ _get(i - 1); }
  I get(I i) { return _get(i) ^ _get(i - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, q;
  cin >> n >> q;
  fenwick tree(n);
  for (I i = 0; i < n; ++i) {
    I a_i;
    cin >> a_i;
    tree.set(i, a_i);
  }

  while (q--) {
    string op;
    I a, b;
    cin >> op >> a >> b;
    --a, --b;
    if (op[0] == 'z') {
      I v_a = tree.get(a), v_b = tree.get(b);
      tree.set(a, v_a), tree.set(a, v_b);
      tree.set(b, v_b), tree.set(b, v_a);
    } else {
      cout << tree.get(a, b) << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

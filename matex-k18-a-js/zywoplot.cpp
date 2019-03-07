#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I lsb(I x) { return x & (-x); }

struct fenwick {
  vector<I> v;
  I n;
  fenwick(I n) : n(n) { v.assign(n + 1, 0); }
  void set(I i, I x) {
    for (++i; i <= n; i += lsb(i)) {
      v[i] += x;
    }
  }
  I get_prefix(I i) {
    I c = 0;
    for (++i; i > 0; i -= lsb(i)) {
      c += v[i];
    }
    return c;
  }
  I get(I i) { return get_prefix(i) - get_prefix(i - 1); }
  I get(I i, I j) { return get_prefix(j) - get_prefix(i - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  const I max_h = 1e6;
  fenwick tree(max_h + 1);

  vector<I> heights(n);
  for (I &i : heights) {
    cin >> i;
    tree.set(i, +1);
  }

  while (m--) {
    string op;
    I a;
    cin >> op >> a;
    if (op[0] == 'p') {
      cout << tree.get(a, max_h) << '\n';
    } else {
      --a;
      I h;
      cin >> h;
      tree.set(heights[a], -1);
      heights[a] = h;
      tree.set(heights[a], +1);
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

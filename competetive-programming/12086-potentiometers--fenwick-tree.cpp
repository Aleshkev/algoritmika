// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3238

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
#define pI PRIiMAX

// Elegant Fenwick Tree implementation.
// ===

template <typename T>
T lso(T x) {  // Least Significant One.
  return x & (-x);
}

template <typename T>
struct fenwick_tree {
  vector<T> data;
  fenwick_tree(I n) {  // Valid indices will be 1..(n - 1), inclusive.
    data.resize(n);
  }

  I get(I b) {  // Sum in 1..b, inclusive.
    I c = 0;
    while (b > 0) {
      c += data[b];
      b -= lso(b);
    }
    return c;
  }
  I get(I a, I b) {  // Sum in a..b, inclusive.
    return get(b) - (a > 0 ? get(a - 1) : 0);
  }

  void set(I a, I x) {
    I adjust = x - get(a, a);
    while (a < (I)data.size()) {
      data[a] += adjust;
      a += lso(a);
    }
  }
};

int main() {
  for (I q = 1;; ++q) {
    I n;
    scanf("%" pI, &n);

    if (n == 0) break;

    fenwick_tree<I> tree(n + 1);
    for (I i = 1; i <= n; ++i) {
      I x;
      scanf("%" pI, &x);
      tree.set(i, x);
    }

    if (q > 1) printf("\n");
    printf("Case %" pI ":\n", q);

    for (;;) {
      char command[4];
      scanf("%s", command);
      if (command[0] == 'E') {
        break;
      }

      if (command[0] == 'S') {
        I x, r;
        scanf("%" pI " %" pI, &x, &r);
        tree.set(x, r);
      } else if (command[0] == 'M') {
        I x, y;
        scanf("%" pI " %" pI, &x, &y);
        printf("%" pI "\n", tree.get(x, y));
      }
    }
  }
#ifdef __MINGW32__
  system("pause");
#endif
  return 0;
}

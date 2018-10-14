#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
#define pI PRIiMAX

// Elegant Union-Find Disjoint Set implementation
// ===

struct disjoint_set {
  vector<I> parent;
  disjoint_set(I n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
  }

  I root(I a) {
    if (parent[a] != a) {
      parent[a] = root(parent[a]);
    }
    return parent[a];
  }

  bool unite(I a, I b) {
    I root_a = root(a), root_b = root(b);
    if (root_a == root_b) return false;

    parent[root_b] = root_a;

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I q;
  scanf("%" pI, &q);

  // Honestly, with every problem I solve, the input seems to get even weirder
  // and harder to parse.
  I n;
  scanf("%" pI, &n);
  for (I qi = 0; qi < q; ++qi) {
    disjoint_set fau(n + 1);  // Protip: FAU stands for Find-And-Union.

    I successful = 0, unsuccessful = 0;
    for (;;) {
      if (scanf("%" pI, &n) > 0) {
        // Can read new `n`, beginning of new test case.
        printf("%" pI ",%" pI "\n\n", successful, unsuccessful);
        break;
      } else {
        char command;
        I a, b;

        if (scanf(" %c %" pI " %" pI, &command, &a, &b) < 1) {
          // End of last test case.
          printf("%" pI ",%" pI "\n", successful, unsuccessful);
          break;
        }

        if (command == 'c') {
          fau.unite(a, b);
        } else if (command == 'q') {
          if (fau.root(a) == fau.root(b)) {
            ++successful;
          } else {
            ++unsuccessful;
          }
        }
      }
    }
  }

#ifdef __MINGW32__
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I lim = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> vertical(n), horizontal(n);
  for (I &i : vertical) cin >> i;
  for (I &i : horizontal) cin >> i;

  const I none = 0;
  cout << [&]() {
    I c = 1;
    I ax = 0, ay = 0, bx = 0, by = 0;
    --vertical[0], --horizontal[0];
    bool last_equal = true;
    for (I i = 2; i < 2 * n; ++i) {
      if (vertical[ay] > 0)
        ++ax;
      else
        ++ay;

      if (horizontal[bx] > 0)
        ++by;
      else
        ++bx;

      if (ax >= n || ay >= n || bx >= n || by >= n) return none;

      --vertical[ay];
      --horizontal[ax];

      if (ax == bx && ay == by) {
        if (!last_equal) c = (2 * c) % lim;
        last_equal = true;
      } else {
        last_equal = false;

        --vertical[by];
        --horizontal[bx];
      }
    }
    if (ax != n - 1 || ay != n - 1 || bx != n - 1 || by != n - 1) return none;
    for (I i : vertical)
      if (i != 0) return none;
    for (I i : horizontal)
      if (i != 0) return none;

    return c;
  }() << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

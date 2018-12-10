#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  auto for_x = [&](I x) {
    I c = 0;
    for (I i = 0; i < n; ++i) {
      c += v[i] * (abs(x - i) + abs(i - 0) + abs(0 - x));
    }
    return 2 * c;
  };

  I best = inf;
  for (I i = 0; i < n; ++i) {
    best = min(best, for_x(i));
  }
  cout << best << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

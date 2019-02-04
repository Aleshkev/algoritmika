#include <bits/stdc++.h>

using namespace std;

typedef double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  F h, d;
  cin >> h >> d;

  F lo = 0.0, hi = h;
  while (abs(lo - hi) > 0.0001) {
    F a = (lo + hi) / 2;
    if (a * a + d * d < (h - a) * (h - a)) {
      lo = a;
    } else {
      hi = a;
    }
  }

  cout << fixed << setprecision(2) << lo << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

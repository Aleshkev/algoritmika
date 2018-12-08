#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;

I k, n;
vector<I> p;

bool ok(I x) {
  I handled = -1;
  I used = 0;
  for (I i : p) {
    if (i > handled) {
      ++used;
      if (used > k) return false;
      handled = i + 2 * x;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;

  while (q--) {
    cin >> k >> n;
    p.resize(n);
    for (I &i : p) {
      cin >> i;
      i *= 2;
    }
    sort(p.begin(), p.end());

    I lo = 0, hi = 2 * p.back();
    while (lo < hi) {
      I mid = (lo + hi) / 2;
      if (ok(mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << fixed << setprecision(1) << F(lo) / (F)2 << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

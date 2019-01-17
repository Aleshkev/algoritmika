#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
typedef long double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k, w, d;
  cin >> n >> k >> w >> d;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  vector<bool> is_div(n);
  for (I i = 0; i < n; ++i) is_div[i] = (v[i] % k == 0);

  I hi = 0, undiv = 0, sum = 0;
  I best_lo, best_len = 0, best_sum = 0;
  for (I lo = 0; lo < n; ++lo) {
    if (lo > 0) undiv -= (!is_div[lo - 1]), sum -= v[lo - 1];

    while (hi < n && undiv < w) {
      undiv += (!is_div[hi]), sum += v[hi];
      ++hi;
    }
    while (hi < n && is_div[hi]) sum += v[hi], ++hi;

    I len = hi - lo;
    if (len > best_len || (len == best_len && sum >= best_sum)) {
      best_lo = lo, best_len = len, best_sum = sum;
    }
  }

  if (best_len < 1) {
    cout << "NIE";
  } else {
    cout << best_len << '\n';
    cout << fixed << setprecision(d) << (F)best_sum / (F)best_len << '\n';
    for (I i = best_lo; i < best_lo + best_len; ++i) cout << v[i] << ' ';
  }
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

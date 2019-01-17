#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I f_lower_bound(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (f(mid)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k;
  cin >> n >> k;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  auto is_ok = [&](I x) {
    I hi = 0, rem = 0, sum = 0;
    for (I lo = 0; lo < n; ++lo) {
      if (lo > 0) rem -= !v[lo - 1], sum -= v[lo - 1];
      while (hi < n && rem < x) rem += !v[hi], sum += v[hi], ++hi;
      while (hi < n && v[hi]) sum += v[hi], ++hi;
      if (sum >= k) return true;
    }
    return false;
  };

  I x = f_lower_bound(0, n + 1, [&](I i) { return !is_ok(i); });
  if (x <= n)
    cout << x << '\n';
  else
    cout << "NIE" << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

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

  I n;
  cin >> n;

  vector<I> v(n);
  for (I &i : v) cin >> i;
  sort(v.begin(), v.end());

  I max_c = 0;
  for (I i = 0; i < n; ++i) {
    I j = f_lower_bound(i + 1, n, [&](I j) { return v[i] + v[i + 1] > v[j]; });
    max_c = max(max_c, j - i);
  }
  cout << max_c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

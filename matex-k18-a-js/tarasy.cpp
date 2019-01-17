#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k;
  cin >> n >> k;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  auto longest = [&]() {
    I m = n - 1;
    vector<I> w(m);
    for (I i = 0; i < m; ++i) {
      w[i] = max((I)0, v[i + 1] - v[i]);
    }

    I hi = 0, sum = 0;
    I max_len = 1;
    for (I lo = 0; lo < m; ++lo) {
      if (lo > 0) sum -= w[lo - 1];
      while (hi < m && sum + w[hi] <= k) sum += w[hi], ++hi;
      max_len = max(max_len, hi - lo + 1);
    }
    return max_len;
  };

  I x = longest();
  reverse(v.begin(), v.end());
  I y = longest();
  cout << max(x, y) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

I qpow(I n, I k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  I half = qpow(n, k / 2);
  return half * half * (k % 2 == 1 ? n : 1);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n;
  cin >> n;

  const vector<I> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,
                            41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
  constexpr I lim = 1e14;

  vector<I> d(n + 1, lim);
  d[1] = 1;

  for (I p : primes) {
    vector<I> t = d;
    for (I i = 0; i <= n; ++i) {
      for (I k = 0;; ++k) {
        if (i * (k + 1) > n || d[i] * qpow(p, k) > lim) break;
        t[i * (k + 1)] = min(t[i * (k + 1)], d[i] * qpow(p, k));
      }
    }
    d = t;
  }
  cout << d[n] << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

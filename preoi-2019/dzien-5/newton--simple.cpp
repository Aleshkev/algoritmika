#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I qpow(I base, I exp, I p) {
  I ans = 1;
  while (exp) {
    if (exp & 1) {
      ans = ans * base % p;
    }
    exp >>= 1;
    base = base * base % p;
  }
  return ans % p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k;
  cin >> n >> k;

  const I p = 1e9 + 7;

  I c = 1;
  for (I i = 0; i < k; ++i) {
    c = c * (n - i) % p;
  }
  I z = 1;
  for (I i = 2; i <= k; ++i) {
    z = z * qpow(i, p - 2, p) % p;
  }
  cout << c * z % p << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

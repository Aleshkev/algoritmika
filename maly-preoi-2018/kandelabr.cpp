#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  const I lim = 1e5;
  vector<bool> is_prime(lim + 1, true);
  vector<I> primes;
  for (I i = 2; i <= lim; ++i) {
    if (is_prime[i]) primes.push_back(i);
    for (I j = i * i; j <= lim; j += i) is_prime[j] = false;
  }
  cout << primes.size() << endl;

  I n, m;
  cin >> n >> m;

  vector<I> v(n);
  for (I i = 0; i < n; ++i) cin >> v[i];

  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;

    for (I prime : primes) {
      bool ok = true;
      for (I i = a; i <= b; ++i) {
        if (v[i] % prime == 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << prime << '\n';
        break;
      }
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

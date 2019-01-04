#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I max_k = 1e6;
  vector<I> is_prime(max_k + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (I i = 2; i <= max_k; ++i) {
    if (!is_prime[i]) continue;

    for (I j = i * i; j <= max_k; j += i) {
      is_prime[j] = false;
    }
  }

  vector<I> v(max_k + 1);
  partial_sum(is_prime.begin(), is_prime.end(), v.begin());

  I q;
  cin >> q;
  while (q--) {
    I a, b;
    cin >> a >> b;
    cout << v[b] - v[a - 1] << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

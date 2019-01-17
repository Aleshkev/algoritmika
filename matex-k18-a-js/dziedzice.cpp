#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> v(n);
  for (I &i : v) cin >> i;
  for (I &i : v) i *= 2;

  vector<I> u(n);
  partial_sum(v.begin(), v.end(), u.begin());
  u.insert(u.begin(), 0);
  I ideal = u.back() / 2;

  I c = 0;
  auto propose = [&](I i, I j) {
    // Nie zmienia wyniku na zły, nawet jeśli i, j są bezsensowne.
    if (i < 0 || j <= i || j > n) return;
    c = max(c, min(u[j] - u[i], u.back() - (u[j] - u[i])));
  };

  for (I i = 0; i < n; ++i) {
    I j = upper_bound(u.begin(), u.end(), u[i] + ideal - 1) - u.begin();
    // Najlepsze rozwiązanie na off-by-one error.
    propose(i, j);
    propose(i, j - 1);
    propose(i, j + 1);
  }
  cout << c / 2 << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

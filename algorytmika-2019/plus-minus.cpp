#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

#define propose(A, B) A = max(A, B)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  vector<I> plus(n, 0), minus(n, 0);
  v[0] > 0 ? plus[0] = v[0] : minus[0] = v[0];

  for (I i = 1; i < n; ++i) {
    plus[i] = plus[i - 1], minus[i] = minus[i - 1];
    if (v[i] > 0)
      propose(plus[i], max<I>(0, minus[i - 1]) + v[i]);
    else
      propose(minus[i], max<I>(0, plus[i - 1]) + v[i]);
  }

  cout << max(plus[n - 1], minus[n - 1]) << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

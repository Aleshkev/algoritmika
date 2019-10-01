#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  vector<vector<F>> d(n, vector<F>(n));
  for (I i = 0; i < n; ++i) d[i][i] = v[i];

  for (I l = 2; l <= n; ++l) {
    for (I i = 0; i + l <= n; ++i) {
      for (I j = i; j + 1 < i + l; ++j) {
        d[i][i + l - 1] =
            max(d[i][i + l - 1], (d[i][j] + d[j + 1][i + l - 1]) / 2);
      }
    }
  }
  cout << fixed << setprecision(7) << d[0][n - 1] << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

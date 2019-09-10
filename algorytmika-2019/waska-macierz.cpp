#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<I>> v(3, vector<I>(n));
  for (I i = 0; i < n; ++i) {
    for (I k = 0; k < 3; ++k) cin >> v[k][i];
  }

  vector<vector<I>> d(3, vector<I>(n, -inf));
  for (I k = 0; k < 3; ++k) d[k][0] = v[k][0];

  for (I i = 1; i < n; ++i) {
    for (I k = 0; k < 3; ++k) {
      for (I last_k = 0; last_k < 3; ++last_k) {
        if (last_k == k) continue;

        d[k][i] = max(d[k][i], v[k][i] + d[last_k][i - 1]);
      }
    }
  }

  cout << max({d[0][n - 1], d[1][n - 1], d[2][n - 1]}) << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

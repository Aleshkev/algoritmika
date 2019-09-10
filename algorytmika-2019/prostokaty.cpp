#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<I>> v(2, vector<I>(n));
  for (I i = 0; i < n; ++i)
    for (I k = 0; k < 2; ++k) cin >> v[k][i];

  vector<vector<I>> d(2, vector<I>(n, -inf));
  d[0][0] = d[1][0] = v[0][0] + v[1][0];

  for (I i = 1; i < n; ++i) {
    for (I k = 0; k < 2; ++k) {
      for (I last_k = 0; last_k < 2; ++last_k) {
        d[k][i] =
            max(d[k][i], d[last_k][i - 1] + abs(v[k][i] - v[last_k][i - 1]));
      }
      d[k][i] += v[!k][i];
    }
  }

  cout << max(d[0][n - 1] + v[0][n - 1], d[1][n - 1] + v[1][n - 1]) << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

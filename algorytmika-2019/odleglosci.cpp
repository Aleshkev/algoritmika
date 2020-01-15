#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef long double F;
constexpr F inf = 1e666;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<F>> d(n, vector<F>(n, inf));
  while (m--) {
    I a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    d[a][b] = w;
  }
  for (I i = 0; i < n; ++i) d[i][i] = 0;

  auto floyd_warshall = [&](vector<vector<F>> &d) {
    for (I k = 0; k < n; ++k)
      for (I i = 0; i < n; ++i)
        for (I j = 0; j < n; ++j)
          if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
  };

  floyd_warshall(d);
  auto t = d;
  floyd_warshall(t);

  for (I a = 0; a < n; ++a) {
    for (I b = 0; b < n; ++b) {
      cout << (t[a][b] >= inf
                   ? "*"
                   : abs(d[a][b] - t[a][b]) >= (F)1 ? "-oo"
                                                    : to_string((I)t[a][b]))
           << " ";
    }
    cout << "\n";
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

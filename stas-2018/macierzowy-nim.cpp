#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;
  while (q--) {
    I n, m;
    cin >> n >> m;
    vector<vector<I>> v(n, vector<I>(m));
    for (I i = 0; i < n; ++i)
      for (I j = 0; j < m; ++j) cin >> v[i][j];

    vector<vector<I>> d(n, vector<I>(m));
    for (I i = 0; i < n; ++i) {
      d[i][m - 1] = v[i][m - 1];
      for (I j = m - 2; j >= 0; --j) {
        d[i][j] = v[i][j] - 1;
        if (d[i][j + 1] <= d[i][j]) ++d[i][j];
      }
    }

    I r = 0;
    for (I i = 0; i < n; ++i) {
      r ^= d[i][0];
    }
    cout << (r != 0 ? "FIRST" : "SECOND") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
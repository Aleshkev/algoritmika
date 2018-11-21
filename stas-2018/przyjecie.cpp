// Also known as EDIST - Edit distance from SPOJ.
// https://www.spoj.com/problems/EDIST/

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I q;
  cin >> q;

  while (q--) {
    string a, b;
    cin >> a >> b;
    I n = a.size(), m = b.size();

    vector<vector<I>> dist(n + 1, vector<I>(m + 1));

    for (I i = 0; i <= n; ++i) dist[i][0] = i;
    for (I i = 0; i <= m; ++i) dist[0][i] = i;

    for (I i = 1; i <= n; ++i) {
      for (I j = 1; j <= m; ++j) {
        if (a[i - 1] == b[j - 1]) {
          dist[i][j] = dist[i - 1][j - 1];
        } else {
          dist[i][j] =
              min({dist[i - 1][j - 1], dist[i - 1][j], dist[i][j - 1]}) + 1;
        }
      }
    }

    cout << dist[n][m] << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

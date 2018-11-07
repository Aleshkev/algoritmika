#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<I>> v(m, vector<I>(n));
  for (I k = 0; k < m; ++k) {
    for (I i = 0; i < n; ++i) {
      cin >> v[k][i];
      --v[k][i];
    }
  }

  vector<vector<I>> index(m, vector<I>(n));
  for (I k = 0; k < m; ++k) {
    for (I i = 0; i < n; ++i) {
      index[k][v[k][i]] = i;
    }
  }

  I c = 0;
  for (I i = 0; i < n;) {
    I j = 1;
    for (; i + j < n; ++j) {
      bool move_ok = true;
      for (I k = 1; k < m; ++k) {
        if (v[k][index[k][v[0][i]] + j] != v[0][i + j]) {
          move_ok = false;
          break;
        }
      }
      if (!move_ok) break;
    }
    c += j * (j + 1) / 2;
    // cout << i << ": " << j << '\n';
    i += j;
  }

  cout << c << '\n';

  // #ifdef __MINGW32__
  //   cout.flush();
  //   system("pause");
  // #endif
  return 0;
}

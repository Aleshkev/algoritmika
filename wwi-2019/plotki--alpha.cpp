#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<I>> v(3, vector<I>(n));
  for (I k = 0; k < 3; ++k) {
    for (I i = 0; i < n; ++i) {
      I a;
      cin >> a;
      v[k][a] = i;
    }
  }

  I c = 0;
  for (I i = 0; i < n; ++i) {
    for (I j = 0; j < n; ++j) {
      if (v[0][i] < v[0][j] && v[1][i] < v[1][j] && v[2][i] < v[2][j]) {
        ++c;
      }
    }
  }
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

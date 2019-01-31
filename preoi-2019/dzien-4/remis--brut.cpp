#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  I c = 0;
  for (I i = 0; i <= n - m; ++i) {
    for (I j = i + m; j <= n; j += m) {
      vector<I> count(m + 1);
      for (I k = i; k < j; ++k) ++count[v[k]];

      bool ok = true;
      for (I k = 1; k <= m; ++k) {
        if (count[k] != (j - i) / m) {
          ok = false;
          break;
        }
      }
      if (ok) ++c;
    }
  }

  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

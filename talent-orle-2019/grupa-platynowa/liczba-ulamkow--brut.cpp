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

    I x = 0;
    for (I a = 1; a <= n; ++a) {
      for (I b = 1; b <= n; ++b) {
        for (I c = 1; c <= m; ++c) {
          for (I d = 1; d <= m; ++d) {
            if (a * d == c * b) {
              ++x;
              goto next_ab;
            }
          }
        }
      next_ab:;
      }
    }
    cout << x << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

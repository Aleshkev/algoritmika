#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  for (;;) {
    I q;
    cin >> q;
    if (q == 0) break;
    I n, m;
    cin >> n >> m;
    while (q--) {
      I x, y;
      cin >> x >> y;
      x -= n, y -= m;

      cout << (x == 0 || y == 0
                   ? "divisa"
                   : x < 0 ? (y < 0 ? "SO" : "NO") : (y < 0 ? "SE" : "NE"))
           << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
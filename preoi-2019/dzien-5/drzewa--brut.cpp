#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I w, h;
  cin >> w >> h;

  I best_c = -1, n_best = 0;
  for (I x = 0; x < w; ++x) {
    for (I y = 0; y < h; ++y) {
      vector<vector<bool>> visible(w, vector<bool>(h, false));
      for (I dx = -x; dx < w - x; ++dx) {
        for (I dy = -y; dy < h - y; ++dy) {
          if ((dx == 0 && dy == 0) || __gcd(abs(dx), abs(dy)) != 1) continue;
          visible[x + dx][y + dy] = true;
        }
      }

      I c = 0;
      for (I xi = 0; xi < w; ++xi) {
        for (I yi = 0; yi < h; ++yi) {
          c += visible[xi][yi];
        }
      }
      if (c > best_c) {
        best_c = c;
        n_best = 1;
      } else if (c == best_c) {
        ++n_best;
      }
    }
  }
  cout << best_c << ' ' << n_best << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

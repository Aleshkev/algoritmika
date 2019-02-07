#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

I unique(I a, I b, I c) {
  return 3 - (a == 0 || a == b || a == c) - (b == 0 || b == c) - (c == 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  string s;
  cin >> s;

  I _a[4][4][4][4], _b[4][4][4][4];
  auto *dp_new = _a, *dp_prev = _b;

#define iter_grid                  \
  for (I x2 = 0; x2 < 4; ++x2)     \
    for (I x1 = 0; x1 < 4; ++x1)   \
      for (I y2 = 0; y2 < 4; ++y2) \
        for (I y1 = 0; y1 < 4; ++y1)

  iter_grid dp_prev[x2][x1][y2][y1] = -inf;
  dp_prev[0][0][0][0] = 0;

  for (I i = 0; i < n; ++i) {
    I c = (s[i] == 'M' ? 1 : s[i] == 'F' ? 2 : s[i] == 'B' ? 3 : -inf);

    iter_grid dp_new[x2][x1][y2][y1] = -inf;

    iter_grid {
      dp_new[x1][c][y2][y1] = max(dp_new[x1][c][y2][y1],
                                  dp_prev[x2][x1][y2][y1] + unique(x2, x1, c));
      dp_new[x2][x1][y1][c] = max(dp_new[x2][x1][y1][c],
                                  dp_prev[x2][x1][y2][y1] + unique(y2, y1, c));
    }
    swap(dp_new, dp_prev);
  }

  I best = 0;
  iter_grid best = max(best, dp_prev[x2][x1][y2][y1]);
  cout << best << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

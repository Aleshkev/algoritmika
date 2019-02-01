#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I w, h;
  cin >> w >> h;

  I large_w = 2 * w - 1, large_h = 2 * h - 1;

  I o = 0;
  vector<vector<I>> partial(2 * w - 1, vector<I>(2 * h - 1, 0));
  {
    I x = w - 1, y = h - 1;

    if (x > 0) partial[x - 1][y] = 1;
    if (x < large_w - 1) partial[x + 1][y] = 1;
    if (y > 0) partial[x][y - 1] = 1;
    if (y < large_h - 1) partial[x][y + 1] = 1;
    for (I dx = 1; dx < w; ++dx) {
      for (I dy = 1; dy < h; ++dy) {
        if (__gcd(dx, dy) != 1) continue;
        partial[x - dx][y - dy] = partial[x + dx][y - dy] =
            partial[x - dx][y + dy] = partial[x + dx][y + dy] = 1;
      }
    }
  }

  for (I x = 1; x < large_w; ++x) partial[x][0] += partial[x - 1][0];
  for (I y = 1; y < large_h; ++y) partial[0][y] += partial[0][y - 1];
  for (I x = 1; x < large_w; ++x)
    for (I y = 1; y < large_h; ++y)
      partial[x][y] +=
          partial[x - 1][y] + partial[x][y - 1] - partial[x - 1][y - 1];

  for (I x = 0; x < large_w; ++x) {
    for (I y = 0; y < large_h; ++y) {
    }
  }

  auto get_partial = [&](I bx, I by, I ex, I ey) {
    return (partial[ex][ey] - (bx > 0 ? partial[bx - 1][ey] : 0) -
            (by > 0 ? partial[ex][by - 1] : 0) +
            (bx > 0 && by > 0 ? partial[bx - 1][by - 1] : 0));
  };

  I best_c = -1, n_best = 0;
  for (I x = 0; x < w; ++x) {
    for (I y = 0; y < h; ++y) {
      I c = get_partial(x, y, x + w - 1, y + h - 1);
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

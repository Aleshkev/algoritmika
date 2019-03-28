#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I h, w, q;
  cin >> h >> w >> q;

  vector<vector<I>> v(w, vector<I>(h));
  for (I y = 0; y < h; ++y)
    for (I x = 0; x < w; ++x) cin >> v[x][y];

  vector<I> max_with_x(w, 0), max_with_y(h, 0);
  for (I x = 0; x < w; ++x) {
    for (I y = 0; y < h; ++y) {
      if (v[x][y] > v[x][max_with_x[x]]) max_with_x[x] = y;
      if (v[x][y] > v[max_with_y[y]][y]) max_with_y[y] = x;
    }
  }
  I c = 0;
  for (I x = 0; x < w; ++x) {
    for (I y = 0; y < h; ++y) {
      if (y == max_with_x[x] && x == max_with_y[y]) {
        ++c;
      }
    }
  }

  while (q--) {
    I r, x, y;
    cin >> y >> x >> r;
    --x, --y;

    v[x][y] = r;

    if (x == max_with_y[y] && y == max_with_x[x]) {
      cout << c << '\n';
      continue;
    }

    if (v[x][y] > v[x][max_with_x[x]]) {
      // Nova plej granda en vertikalo.
      if (x == max_with_y[max_with_x[x]]) {
        // Elĵeti la malnovan.
        --c;
      }
      max_with_x[x] = y;
    }
    if (v[x][y] > v[max_with_y[y]][y]) {
      // Nova plej granda en horizontalo.
      if (y == max_with_x[max_with_y[y]]) {
        // Elĵeti la malnovan.
        --c;
      }

      max_with_y[y] = x;
    }

    if (x == max_with_y[y] && y == max_with_x[x]) {
      // Iĝi la plej granda.
      ++c;
    }

    cout << c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

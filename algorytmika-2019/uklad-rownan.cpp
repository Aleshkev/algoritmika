#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef long double F;

constexpr F eps = 1e-9;
bool is_zero(F x) { return abs(x) < eps; }

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I h, w;
  cin >> h >> w;

  vector<vector<F>> v(h, vector<F>(w + 1));

  for (I y = 0; y < h; ++y)
    for (I x = 0; x <= w; ++x) cin >> v[y][x];

  // Słowa kluczowe: Gauss, rozwiązywanie równań liniowych, długie debugowanie.
  vector<I> d(w, -1);
  for (I col = 0, row = 0; col < w && row < h; ++col) {
    I s = row;
    for (I y = row; y < h; ++y)
      if (abs(v[y][col]) > abs(v[s][col])) s = y;
    if (is_zero(v[s][col])) continue;

    swap(v[s], v[row]);

    d[col] = row;

    for (I y = 0; y < h; ++y) {
      if (y == row) continue;
      F m = v[y][col] / v[row][col];
      for (I x = col; x <= w; ++x) v[y][x] -= v[row][x] * m;
    }

    ++row;
  }

  vector<F> r(w, 0);
  for (I x = 0; x < w; ++x)
    if (d[x] != -1) r[x] = v[d[x]][w] / v[d[x]][x];

  for (F i : r) cout << fixed << setprecision(20) << i << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

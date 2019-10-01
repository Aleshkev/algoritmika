#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I h, w;
  cin >> h >> w;
  vector<vector<I>> v(w, vector<I>(h));

  for (I y = 0; y < h; ++y)
    for (I x = 0; x < w; ++x) cin >> v[x][y];

  const I max_k = 1000;
  vector<I> sieve(max_k + 1, -1);
  for (I i = 2; i <= max_k; ++i) {
    if (sieve[i] != -1) continue;
    for (I j = i * i; j <= max_k; j += i) {
      sieve[j] = i;
    }
  }
  vector<vector<I>> factors(6);
  for (I c : {2, 5}) {
    auto &table = factors[c];
    table.resize(max_k + 1);
    table[0] = 1;
    for (I i = 1; i <= max_k; ++i) {
      I x = i;
      for (; sieve[x] != -1; x /= sieve[x]) {
        if (sieve[x] == c) ++table[i];
      }
      if (x == c) ++table[i];
    }
  }

  auto get_min_div = [&](I c) {
    vector<vector<I>> d(w, vector<I>(h));
#define val(X, Y) (factors[c][abs(v[X][Y])])
    d[0][0] = val(0, 0);
    for (I x = 1; x < w; ++x) d[x][0] = d[x - 1][0] + val(x, 0);
    for (I y = 1; y < h; ++y) d[0][y] = d[0][y - 1] + val(0, y);
    for (I x = 1; x < w; ++x)
      for (I y = 1; y < h; ++y)
        d[x][y] = min(d[x - 1][y], d[x][y - 1]) + val(x, y);
    return d[w - 1][h - 1];
  };

  I x_2 = get_min_div(2), x_5 = get_min_div(5);
  I r = min(x_2, x_5);

  for (I x = 0; x < w; ++x)
    for (I y = 0; y < h; ++y)
      if (v[x][y] == 0 && r > 1) r = 1;

  cout << r << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

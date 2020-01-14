#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

I qpow(I n, I k, I p) {
  if (k == 0) return 1;
  if (k == 1) return n % p;
  I half = qpow(n, k / 2, p);
  return half * half % p * (k % 2 == 1 ? n : 1) % p;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, p;
  cin >> n >> p;

  vector<vector<I>> v(n + 1, vector<I>(n + 2));
  for (I i = 0; i < n + 1; ++i) {
    I a;
    cin >> a >> v[i][n + 1];
    I m = 1;
    for (I x = n; x >= 0; --x) {
      v[i][x] = m;
      m = (m * a) % p;
    }
  }

  vector<I> d(n + 2, -1);
  for (I col = 0, row = 0; col < n + 1 && row < n + 2; ++col) {
    I s = row;
    for (I y = row; y < n + 1; ++y)
      if (v[y][col] > 0) s = y;
    if (v[s][col] == 0) continue;

    swap(v[s], v[row]);

    d[col] = row;

    for (I y = 0; y < n + 1; ++y) {
      if (y == row) continue;
      I m = v[y][col] * qpow(v[row][col], p - 2, p) % p;
      for (I x = col; x <= n + 1; ++x)
        v[y][x] = ((v[y][x] + p * p - v[row][x] * m) % p);
    }

    ++row;
  }

  vector<I> r(n + 1, 0);
  for (I x = 0; x < n + 1; ++x)
    if (d[x] != -1) r[x] = v[d[x]][n + 1] * qpow(v[d[x]][x], p - 2, p) % p;

  reverse(r.begin(), r.end());
  for (I i : r) cout << i << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

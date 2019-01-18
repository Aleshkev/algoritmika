#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  string dir, rot;
  cin >> n >> dir >> rot;
  I d = (dir == "POLNOC" ? 0 : dir == "WSCHOD" ? 1 : dir == "POLUDNIE" ? 2 : 3);
  I r = (rot == "PRAWO" ? 1 : -1);

  I x1, x2, y1, y2;
  cin >> x1 >> x2 >> y1 >> y2;

  vector<I> change_x = {0, 1, 0, -1}, change_y = {1, 0, -1, 0};

  vector<vector<vector<I>>> u = {
      {{1, 1}, {n, 1}}, {{1, n}, {1, 1}}, {{n, n}, {1, n}}, {{n, 1}, {n, n}}};
  I x = u[d][r == 1 ? 0 : 1][0] - change_x[d],
    y = u[d][r == 1 ? 0 : 1][1] - change_y[d];

  vector<vector<I>> result(x2 - x1 + 1, vector<I>(y2 - y1 + 1));

  I c = 1;
  for (I i = 1; i <= 2 * n - 1; ++i) {
    I l = n - i / 2;
    for (I j = 0; j < l; ++j) {
      x += change_x[d], y += change_y[d];
      if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
        result[x - x1][y - y1] = c;
      }
      ++c;
    }
    d = (d + 4 + r) % 4;
  }

  for (I y = y2 - y1; y >= 0; --y) {
    for (I x = 0; x <= x2 - x1; ++x) {
      cout << result[x][y] << ' ';
    }
    cout << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

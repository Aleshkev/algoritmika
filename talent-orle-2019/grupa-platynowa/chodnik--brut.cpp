#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> xs, ys;
  for (I i = 0; i < n; ++i) {
    I x, y;
    cin >> x >> y;
    xs.push_back(x), ys.push_back(y);
  }

  I p;
  cin >> p;
  for (I i = 0; i < p; ++i) {
    I x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    I c = 0;
    for (I i = 0; i < n; ++i) {
      I x = xs[i], y = ys[i];
      if (((x == x1 || x == x2) && y1 <= y && y <= y2) ||
          ((y == y1 || y == y2) && x1 <= x && x <= x2)) {
        ++c;
      }
    }

    cout << c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

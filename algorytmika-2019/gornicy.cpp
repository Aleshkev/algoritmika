#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;
const I inf = 1e9;
#define propose(A, B) A = max(A, B)

I unique(I a, I b, I c) { return 3 - (a == b || a == c) - (b == c); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I _a[3][3][3][3], _b[3][3][3][3];
  auto *current = _a, *previous = _b;

#define walk                       \
  for (I x2 = 0; x2 < 3; ++x2)     \
    for (I x1 = 0; x1 < 3; ++x1)   \
      for (I y2 = 0; y2 < 3; ++y2) \
        for (I y1 = 0; y1 < 3; ++y1)

  walk previous[x2][x1][y2][y1] = 0;

  string s;
  I n = s.size();
  cin >> n >> s;

  for (I i = 0; i < n; ++i) {
    char ch = s[i];
    const I c = (ch == 'M' ? 0 : ch == 'F' ? 1 : 2);

    walk current[x2][x1][y2][y1] = -inf;

    walk {
      propose(current[x1][c][y2][y1],
              previous[x2][x1][y2][y1] + unique(x2, x1, c));
      propose(current[x2][x1][y1][c],
              previous[x2][x1][y2][y1] + unique(y2, y1, c));
    }
    swap(current, previous);
  }

  I c = 0;
  walk c = max(c, previous[x2][x1][y2][y1]);
  cout << c - 6 << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

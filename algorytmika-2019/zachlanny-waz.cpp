#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I h, w;
  cin >> h >> w;

  constexpr I max_n = 50;
  I n = max(h, w);

  static I v[max_n + 20][max_n + 20];
  for (I y = 0; y < h; ++y) {
    string s;
    cin >> s;
    for (I x = 0; x < w; ++x) v[x + 1][y + 1] = s[x] - '0';
  }
#define get(i, a) v[a + 1][i - a + 1]
  auto sum_unique = [&](I i, I a, I b, I c) {
    I r = get(i, a);
    if (a != b) r += get(i, b);
    if (a != c && b != c) r += get(i, c);
    return r;
  };

  // Szczerze nie mam pojęcia czemu +10, ale wreszcie zadziałało i mogę iść
  // spać.
  static I r[2 * max_n + 10][max_n + 10][max_n + 10][max_n + 10];

  r[0][0][0][0] = get(0, 0);

  for (I i = 1; i <= w + h; ++i) {
    for (I a = 0; a <= i && a <= w; ++a)
      for (I b = 0; b <= i && b <= w; ++b)
        for (I c = 0; c <= i && c <= w; ++c) {
          r[i][a][b][c] = 0;
          for (I d = 0; d < 2; ++d)
            for (I e = 0; e < 2; ++e)
              for (I f = 0; f < 2; ++f) {
                if (a - d >= 0 && b - e >= 0 && c - f >= 0)
                  r[i][a][b][c] =
                      max(r[i][a][b][c], r[i - 1][a - d][b - e][c - f]);
              }

          I s = sum_unique(i, a, b, c);
          r[i][a][b][c] += s;
        }
  }

  auto score = [&](I x, I y) {
    I i = x + y, a = x;
    return r[i][a][a][a];
  };

  cout << score(w - 1, h - 1) << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

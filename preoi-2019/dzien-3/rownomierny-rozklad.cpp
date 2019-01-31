// I had a really nice solution in Python, but it unfortunately doesn't seem to
// work. Also, SIO2 is really slow with checking Python solutions (over 20
// minutes since submition and still no verdict). So I just wrote this C++
// solution. Forgive me, Guido.
//
// def f(a=(9, 15, 20, 25, 31), n=20):
//     m = n // 5
//     s = {(0,) * 5: 1}
//     for _ in range(n):
//         z = defaultdict(lambda: 0)
//         for k, v in s.items():
//             for i in range(5):
//                 if k[i] + 1 > m:
//                     continue
//                 z[k[:i] + (k[i] + 1,) + k[i + 1:]] += v * a[i]
//         s = z
//     return s[(m,) * 5] / 100 ** n
//
// n = int(input())
// a = list(map(lambda x: int(100 * float(x)), input().split()))
// print(f"{f(a, n):.11f}")

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef long double F;

// I'd place it inside main() but then I would have to fill these with zeros.
F p[5];
F d1[5][5][5][5][5], d2[5][5][5][5][5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  I m = n / 5;

  for (I i = 0; i < 5; ++i) cin >> p[i];

  auto *old_dp = d1, *new_dp = d2;
  old_dp[0][0][0][0][0] = 1;
  for (I i = 0; i < n; ++i) {
    // Clear.
    for (I a = 0; a < 5; ++a)
      for (I b = 0; b < 5; ++b)
        for (I c = 0; c < 5; ++c)
          for (I d = 0; d < 5; ++d)
            for (I e = 0; e < 5; ++e) new_dp[a][b][c][d][e] = 0;

    // Fill.
    for (I a = 0; a < 5; ++a)
      for (I b = 0; b < 5; ++b)
        for (I c = 0; c < 5; ++c)
          for (I d = 0; d < 5; ++d)
            for (I e = 0; e < 5; ++e) {
              if (a + 1 < 5)
                new_dp[a + 1][b][c][d][e] += old_dp[a][b][c][d][e] * p[0];
              if (b + 1 < 5)
                new_dp[a][b + 1][c][d][e] += old_dp[a][b][c][d][e] * p[1];
              if (c + 1 < 5)
                new_dp[a][b][c + 1][d][e] += old_dp[a][b][c][d][e] * p[2];
              if (d + 1 < 5)
                new_dp[a][b][c][d + 1][e] += old_dp[a][b][c][d][e] * p[3];
              if (e + 1 < 5)
                new_dp[a][b][c][d][e + 1] += old_dp[a][b][c][d][e] * p[4];
            }
    swap(old_dp, new_dp);
  }

  cout << fixed << setprecision(20) << old_dp[m][m][m][m][m] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

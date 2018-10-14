#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(2);

  const I expected_sum = 2000, expected_product = 20e8;

  for (I a = 1; a < expected_sum && a <= expected_product; ++a) {
    for (I b = a; a + b < expected_sum && a * b <= expected_product; ++b) {
      for (I c = b; a + b + c < expected_sum && a * b * c <= expected_product;
           ++c) {
        I alpha = (a + b + c) * 1e6;
        I beta = a * b * c - 1e6;

        if (beta != 0 && alpha % beta == 0) {
          I d = alpha / beta;
          if (c <= d && a + b + c + d <= expected_sum &&
              (a + b + c + d) * 1e6 == a * b * c * d) {
            cout << F(a) / 100.0 << ' ' << F(b) / 100.0 << ' ' << F(c) / 100.0
                 << ' ' << F(d) / 100.0 << '\n';
          }
        }
      }
    }
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

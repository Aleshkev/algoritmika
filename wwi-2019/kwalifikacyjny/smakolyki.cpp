#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> single(n), bottom(n), top(n);
  for (I i = 0; i < n; ++i) cin >> single[i];
  for (I i = 0; i < n - 1; ++i) {
    cin >> bottom[i];
    top[i + 1] = bottom[i];
  }

  constexpr I mod = 1e9 + 7;

  vector<I> left(n), right(n);
  if (bottom[0] > 0)
    left[0] = single[0] + bottom[0] - 1;
  else
    left[0] = 0;
  right[0] = single[0] + bottom[0];
  for (I i = 1; i < n; ++i) {
    if (bottom[i] > 0)
      left[i] = (single[i] + bottom[i] - 1) * right[i - 1] % mod +
                top[i] * left[i - 1] % mod;
    else
      left[i] = 0;

    right[i] = (single[i] + bottom[i]) * right[i - 1] % mod +
               top[i] * left[i - 1] % mod;
  }

  cout << right[n - 1] % mod << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

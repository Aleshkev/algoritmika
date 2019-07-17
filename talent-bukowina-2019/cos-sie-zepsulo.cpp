#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k;
  cin >> n >> k;

  vector<I> v(n), w(n);

  string s;
  cin >> s;
  for (I i = 0; i < n; ++i) v[i] = s[i] - '0';

  w[0] = v[0];
  for (I i = 1; i < n; ++i) {
    for (I j = max<I>(0, i - k + 1); j <= i; ++j) {
      I c = 0;
      for (I l = j; l <= i; ++l) c = c * 10 + v[l];
      w[i] = max(w[i], (j > 0 ? w[j - 1] : 0) + c);
    }
  }

  cout << w[n - 1] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

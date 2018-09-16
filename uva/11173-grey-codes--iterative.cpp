#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I q;
  cin >> q;

  for (I qi = 0; qi < q; ++qi) {
    I n, k;
    cin >> n >> k;

    I c = 0;
    for (I i = 0; i <= n; ++i) {
      if (k >= (1 << i) && (k - (1 << i)) % (1 << (i + 2)) < (1 << (i + 1))) {
        c |= (1 << i);
      }
    }
    cout << c << '\n';
  }

#ifdef __MINGW32__
  system("pause");
#endif
  return 0;
}

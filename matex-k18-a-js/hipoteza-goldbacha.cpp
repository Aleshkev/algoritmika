#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

bool is_prime(I n) {
  if (n <= 2) return true;
  for (I i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I q;
  cin >> q;
  for (I qi = 0; qi < q; ++qi) {
    I n;
    cin >> n;

    for (I a = (n + 1) / 2; a <= n; ++a) {
      I b = n - a;
      if (is_prime(a) && is_prime(b)) {
        cout << b << ' ' << a << '\n';
        break;
      }
    }
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

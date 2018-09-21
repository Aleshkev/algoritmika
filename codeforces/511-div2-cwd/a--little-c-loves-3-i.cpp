#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  bool found = false;

  for (I a = 1; a <= 2; ++a) {
    for (I b = 1; b <= 2; ++b) {
      I c = n - a - b;
      if (c % 3 != 0) {
        cout << a << ' ' << b << ' ' << c << '\n';
        found = true;
        break;
      }
    }
    if (found) break;
  }

  return 0;
}

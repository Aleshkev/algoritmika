#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  while (n >= 10) {
    I m = 0;
    while (n > 0) {
      m += n % 10;
      n /= 10;
    }
    n = m;
  }
  cout << n << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

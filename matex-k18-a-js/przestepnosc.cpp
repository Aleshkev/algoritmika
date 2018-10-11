#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

bool leap(I y) { return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;
  cout << (leap(n) ? "TAK" : "NIE") << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

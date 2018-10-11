#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;
const F pi =
    3.141592653578;  // I *could* use a builtin constant, but when would I brag
                     // about remembering the digits of pi? All of them?

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  F r;
  cin >> r;

  cout << fixed << setprecision(3) << pi * r * r << '\n' << 2 * pi * r << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

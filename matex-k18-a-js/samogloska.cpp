#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  char c;
  cin >> c;

  string s = "eyuioa";

  cout << (count(s.begin(), s.end(), c) == 1 ? "tak" : "nie") << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

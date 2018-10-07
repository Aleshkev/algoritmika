#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  for (I i = 0; i < s.size(); ++i) {
    s[i] = 'A' + 'Z' - s[i];
  }
  cout << s << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

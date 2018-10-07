#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  getline(cin, s);

  string z;
  for (I i = 0; i < s.size(); ++i) {
    if (s[i] == ' ') continue;
    z.push_back(toupper(s[i]));
    if (z.back() == 'U') z.pop_back(), z.push_back('V');
  }

  cout << z << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

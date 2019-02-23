#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I h = 0;

  string s;
  while (cin >> s) {
    for (char c : s) {
      h *= 31;
      h += max((I)0, (I)c - '0');
      h %= (I)1000000000000000003;
    }
  }
  exit(h);

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

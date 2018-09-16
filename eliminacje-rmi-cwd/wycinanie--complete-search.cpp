#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  const I max_n = 400;
  static char s[max_n + 1];
  cin >> s;
  I n = strlen(s);

  I best_len = 0;
  for (I i = 0; i < n; ++i) {
    for (I j = i + best_len; j < n; ++j) {
      // Try to cut i..j, inclusive.

      I len = j - i + 1;

      static char z[max_n + 1];
      I m = n - len;
      copy(s, s + i, z);
      copy(s + j, s + n, z + i);
      z[m] = '\0';
      cout << z << endl;

      for (I k = 0; k < m - len; ++k) {
      }
    }
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

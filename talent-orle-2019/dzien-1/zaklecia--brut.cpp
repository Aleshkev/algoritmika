#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I solve(string &s) {
  I n = s.size();

  I m = 0;

  for (I i = 0; i < n - 4 * m; ++i) {
    for (I l = (n - i) / 4; l > m; --l) {
      bool ok = true;
      for (I j = 0; j < l; ++j) {
        if (s[i + j] == s[i + 2 * l + j] && s[i + j] == s[i + 2 * l - j - 1] &&
            s[i + j] == s[i + 4 * l - j - 1])
          continue;
        ok = false;
        break;
      }
      if (ok) m = max(m, l);
    }
  }
  return m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;

    cout << 4 * solve(s) << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

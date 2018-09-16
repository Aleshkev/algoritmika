#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I q;
  cin >> q;

  for (I qi = 0; qi < q; ++qi) {
    string s;
    cin >> s;
    I n = s.size();
    vector<bool> wins(n);
    wins[n - 1] = true;
    for (I i = n - 2; i >= 0; --i) {
      wins[i] = !wins[i + 1] || (s[i] == s[i + 1] && wins[i + 1]);
    }
    cout << (wins[0] ? "Ania" : "Bogdan") << '\n';
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

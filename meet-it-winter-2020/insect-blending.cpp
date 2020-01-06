#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vector<vector<I>> v(26, vector<I>(n));
  for (char c = 'a'; c <= 'z'; ++c) {
    v[c - 'a'][0] = (s[0] == c);
    for (I i = 1; i < n; ++i) {
      v[c - 'a'][i] = v[c - 'a'][i - 1] + (s[i] == c);
    }
  }

  while (m--) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    I r = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      I x = v[c - 'a'][b] - (a > 0 ? v[c - 'a'][a - 1] : 0);
      r += x * (x + 1) / 2;
    }
    I len = b - a + 1;
    cout << len * (len + 1) / 2 + 1 - r << "\n";
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

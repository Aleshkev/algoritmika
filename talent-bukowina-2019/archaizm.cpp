#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  string s;
  cin >> s;

  vector<bool> v(n);
  v[0] = 0;
  for (I i = 1; i < n; ++i) {
    v[i] = s[i - 1] != s[i];
  }

  I c = 1;
  for (I i = 0; i < n; ++i) {
    if (!v[i]) continue;
    I j = i;
    while (j < n && v[j]) ++j;
    c = max(c, j - i + 1);
    i = j - 1;
  }
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

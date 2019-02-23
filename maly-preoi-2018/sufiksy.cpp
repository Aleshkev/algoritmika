#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string a, b;
  cin >> a >> b;
  I n = a.size(), m = b.size();

  reverse(a.begin(), a.end()), reverse(b.begin(), b.end());

  string s;
  s.push_back('$');
  for (char c : a) s.push_back(c);
  s.push_back('#');
  for (char c : b) s.push_back(c);
  I k = s.size();

  vector<I> mp(k);
  mp[0] = -1;
  for (I i = 1; i < k; ++i) {
    mp[i] = mp[i - 1];
    while (mp[i] > -1 && s[mp[i] + 1] != s[i]) mp[i] = mp[mp[i]];
    ++mp[i];
  }

  vector<I> r(n + 1);
  for (I i = n + 2; i < k; ++i) {
    ++r[mp[i]];
  }

  vector<I> c(n + 1);
  for (I i = n; i >= 1; --i) {
    c[i] = r[i];
    r[mp[i]] += r[i];
  }

  for (I i = 1; i <= n; ++i) {
    cout << c[i] << ' ';
  }
  cout << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}
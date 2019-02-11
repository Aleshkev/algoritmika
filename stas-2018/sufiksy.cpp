#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

vector<I> get_mp(const string &s) {
  I n = s.size() - 1;
  vector<I> r(n + 1);
  r[0] = -1;
  for (I i = 1; i <= n; ++i) {
    r[i] = r[i - 1] + 1;
    while (r[i] > 0 && s[r[i]] != s[i]) {
      r[i] = r[r[i] - 1] + 1;
    }
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
  string s;
  s += "#";
  s += a;
  s += "$";
  s += b;

  auto r = get_mp(s);

  vector<I> v(a.size() + 1);
  for (I i = a.size() + 2; i < s.size(); ++i) {
    ++v[r[i]];
  }

  for (I i = a.size(); i >= 1; --i) {
    v[r[i]] += v[i];
  }

  for (I i = 1; i <= a.size(); ++i) cout << v[i] << ' ';
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

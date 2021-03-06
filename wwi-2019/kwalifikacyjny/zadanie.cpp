#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

vector<I> compute_mp(const string &a) {
  I n = a.size() - 1;
  vector<I> mp(n + 1);
  mp[0] = -1;
  for (I i = 1; i <= n; ++i) {
    mp[i] = mp[i - 1];
    while (mp[i] > -1 && a[mp[i] + 1] != a[i]) mp[i] = mp[mp[i]];
    ++mp[i];
  }
  return mp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I t;
  cin >> t;
  while (t--) {
    I n;
    cin >> n;
    vector<I> v(n);
    for (I &i : v) cin >> i;
    string s(n, '#');
    s[0] = 'a';
    for (I i = 1; i < n; ++i) {
      s[i] = (v[i] == 0 ? 'b' : s[v[i] - 1]);
    }

    vector<I> w = compute_mp('#' + s);
    w.erase(w.begin());

    if (v == w) {
      cout << "TAK\n" << s << '\n';
    } else {
      cout << "NIE\n";
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

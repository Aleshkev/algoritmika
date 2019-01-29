#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

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

  I n, k;
  cin >> n >> k;

  string s;
  cin >> s;
  s.insert(s.begin(), '#');
  vector<I> mp = compute_mp(s);

  for (I i = 1; i <= n; ++i) {
    cout << (i / (i - mp[i]) >= k);
  }
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

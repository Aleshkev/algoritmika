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
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;

  auto v = compute_mp("#" + a + "$" + b);

  for (I i = n + 2; i < n + m + 2; ++i) {
    if (v[i] == n) {
      cout << i - 2 * n << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

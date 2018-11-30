#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;
  const I max_a = 1e6;
  vector<vector<I>> positions(max_a + 1);
  for (I i = 0; i < n; ++i) {
    I a;
    cin >> a;
    positions[a].push_back(i);
  }

  I q;
  cin >> q;
  while (q--) {
    I m;
    cin >> m;

    vector<I> v(m);
    for (I &i : v) cin >> i;

    bool ok = true;
    I position = -1;

    for (I i = 0; i < m; ++i) {
      I b = v[i];
      auto j = upper_bound(positions[b].begin(), positions[b].end(), position);
      if (j == positions[b].end()) {
        ok = false;
        break;
      }
      position = *j;
    }

    cout << (ok ? "TAK" : "NIE") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

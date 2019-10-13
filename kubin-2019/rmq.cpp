#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

// Cześć, Kuba!

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  I max_k = 20;
  vector<vector<I>> v(max_k + 1);
  v[0].resize(n);
  for (I i = 0; i < n; ++i) {
    cin >> v[0][i];
  }

  for (I k = 1; k <= max_k; ++k) {
    v[k].resize(max<I>(n - (1 << k) + 1, 0));
    for (I i = 0; i + (1 << k) <= n; ++i) {
      v[k][i] = min(v[k - 1][i], v[k - 1][i + (1 << k >> 1)]);
    }
  }

  auto get_l = [&](I x) {
    if (x == 0) return (I)0;
    I l = 1;
    while ((1 << l) <= x) ++l;
    return l - 1;
  };

  I m;
  cin >> m;
  while (m--) {
    I a, b;
    cin >> a >> b;
    --a, --b;

    I l = get_l(b - a + 1);

    cout << min(v[l][a], v[l][b - (1 << l) + 1]) << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

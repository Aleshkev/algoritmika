#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<II> v(n);
  for (I i = 0; i < n; ++i) cin >> v[i].second;
  for (I i = 0; i < n; ++i) cin >> v[i].first;
  sort(v.begin(), v.end(),
       [&](II x, II y) { return x.first * y.second > y.first * x.second; });

  F c = 0;
  for (I i = 0; i < n; ++i) {
    I take = min(m, v[i].second);
    c += F(v[i].first * take) / v[i].second;
    m -= take;
  }
  cout << fixed << setprecision(9) << c << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

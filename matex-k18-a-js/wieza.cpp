#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> v(n);
  for (I i = 0; i < n; ++i) {
    cin >> v[i];
    if (i > 0 && v[i] < v[i - 1]) v[i] = v[i - 1];
  }

  for (I i = 0; i < m; ++i) {
    I a;
    cin >> a;
    cout << lower_bound(v.begin(), v.end(), a) - v.begin() << ' ';
  }
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

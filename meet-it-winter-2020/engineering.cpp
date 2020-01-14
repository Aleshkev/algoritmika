#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> a(n), b(n);
  for (I &i : a) cin >> i;
  for (I &i : b) cin >> i;
  vector<vector<I>> v(m);
  for (I i = 0; i < n; ++i) v[--a[i]].push_back(b[i]);

  I k = 0;
  vector<I> d;
  for (auto &w : v) {
    if (w.empty()) ++k;
    sort(w.begin(), w.end());
    for (I i = 0; i + 1 < (I)w.size(); ++i) d.push_back(w[i]);
  }
  sort(d.begin(), d.end());
  cout << accumulate(d.begin(), d.begin() + k, (I)0) << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, b;
  cin >> n >> b;

  vector<I> w(n), v(n);
  for (I i = 0; i < n; ++i) cin >> w[i];
  for (I i = 0; i < n; ++i) cin >> v[i];

  vector<I> d(b + 1);
  vector<vector<I>> t(b + 1);
  for (I i = 0; i < n; ++i) {
    for (I j = b - w[i]; j >= 0; --j) {
      if (d[j] == 0 && j > 0) continue;
      if (d[j + w[i]] < d[j] + v[i]) {
        d[j + w[i]] = d[j] + v[i];
        t[j + w[i]] = t[j];
        t[j + w[i]].push_back(i);
      }
    }
  }
  I best = max_element(d.begin(), d.end()) - d.begin();

  cout << d[best] << "\n" << t[best].size() << "\n";
  for (I i : t[best]) cout << i + 1 << " ";
  cout << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

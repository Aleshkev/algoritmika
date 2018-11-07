#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  for (I i = n - 1; i >= 1; --i) {
    v[i] = v[i] - v[i - 1];
  }

  vector<I> r;
  for (I l = 1; l <= n; ++l) {
    bool ok = true;
    for (I i = l; i < n; i += l) {
      for (I j = 0; j < l && i + j < n; ++j) {
        if (v[i + j] != v[i - l + j]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) r.push_back(l);
  }

  cout << r.size() << '\n';
  for (I i : r) cout << i << ' ';
  cout << '\n';

  return 0;
}

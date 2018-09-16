#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> t(n);
  for (I i = 0; i < n; ++i) cin >> t[i];
  sort(t.begin(), t.end());

  I max_s = 0;
  for (I i = 0; i < n - 2; ++i) {
    for (I j = i + 1; j < n - 1; ++j) {
      I k = (upper_bound(t.begin() + j + 1, t.end(), m - t[i] - t[j]) -
             t.begin() - 1);
      I s;
      if (k > j && (s = t[i] + t[j] + t[k]) <= m) {
        // cout << i << ' ' << j << ' ' << k << ": " << s << endl;
        max_s = max(max_s, s);
      }
    }
  }

  cout << max_s << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

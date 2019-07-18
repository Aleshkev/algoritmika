#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> v(3 * n);
  for (I i = 0; i < n; ++i) {
    cin >> v[i];
    v[2 * n + i] = v[n + i] = v[i];
  }

  vector<I> p(3 * n);
  partial_sum(v.begin(), v.end(), p.begin());
  auto get_sum = [&](I a, I b) {
    return p[n + b] - (n + a > 0 ? p[n + a - 1] : 0);
  };

  I k = (n + 1) / 2;

  // I max_c = 0;
  // for (I i = 0; i < n; ++i) {
  //   I min_s = inf;
  //   for (I j = i - k + 1; j <= i; ++j) {
  //     I s = get_sum(j, j + k - 1);
  //     // for (I l = j; l < j + k; ++l) s += v[(n + l) % n];
  //     // cout << i << " " << j << ": " << s << endl;
  //     min_s = min(min_s, s);
  //   }
  //   // cout << i << ": " << min_s << endl;
  //   max_c = max(max_c, min_s);
  // }
  // cout << max_c << '\n';

  vector<vector<I>> d(n);
  for (I i = 0; i < n; ++i) {
    I s = get_sum(i, i + k - 1);
    d[i].push_back(+s);
    if (i + k < n)
      d[i + k].push_back(-s);
    else
      d[0].push_back(+s), d[(i + k) % n].push_back(-s);
  }
  I max_c = 0;
  multiset<I> m;
  for (I i = 0; i < n; ++i) {
    for (I x : d[i]) {
      x > 0 ? m.insert(x) : m.erase(m.find(-x));
    }
    max_c = max(max_c, *m.begin());
  }
  cout << max_c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

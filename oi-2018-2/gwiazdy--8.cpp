// :c

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  I n, s;
  cin >> n >> s;
  --s;

  vector<I> l(n - 1), r(n - 1);
  for (I i = 0; i < n - 1; ++i) cin >> l[i] >> r[i];

  vector<I> v(n);
  iota(v.begin(), v.end(), 0);
  v.erase(v.begin() + s);

  I min_c = inf;
  vector<I> best_v(n - 1);
  do {
    I c = 0;
    I z = s;
    for (I i = 0; i < n - 1; ++i) {
      if (v[i] < z)
        c += l[i];
      else
        c += r[i];
      z = v[i];
    }
    if (c < min_c) {
      min_c = c;
      copy(v.begin(), v.end(), best_v.begin());
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << min_c << '\n';
  cout << s + 1 << ' ';
  for (I i : best_v) cout << i + 1 << ' ';
  cout << '\n';

  return 0;
}
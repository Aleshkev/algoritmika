#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, b, h, w;
  while (cin >> n >> b >> h >> w) {
    I min_c = inf;
    for (I i = 0; i < h; ++i) {
      I p;
      cin >> p;
      vector<I> v(w);
      for (I &i : v) cin >> i;
      I x = *max_element(v.begin(), v.end());
      if (x >= n && n * p <= b) {
        min_c = min(min_c, n * p);
      }
    }
    if (min_c < inf)
      cout << min_c << '\n';
    else
      cout << "stay home" << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
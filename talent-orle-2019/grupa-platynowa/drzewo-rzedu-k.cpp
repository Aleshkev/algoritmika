#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k, q;
  cin >> n >> k >> q;

  if (k == 1) {
    while (q--) {
      I x, y;
      cin >> x >> y;
      cout << abs(x - y) << '\n';
    }
  } else {
    vector<I> v = {1};
    while (v.back() <= 4 * n) {
      v.push_back(v.back() * k);
    }
    vector<I> u(v.size());
    partial_sum(v.begin(), v.end(), u.begin());

    auto logk = [&](I x) {
      return lower_bound(u.begin(), u.end(), x) - u.begin();
    };

    while (q--) {
      I x, y;
      cin >> x >> y;
      if (logk(x) < logk(y)) swap(x, y);

      I c = 0;
      while (logk(x) > logk(y)) {
        x = (x - (logk(x) > 0 ? u[logk(x) - 1] : 0) - 1) / k +
            (logk(x) > 1 ? u[logk(x) - 2] : 0) + 1;
        ++c;
      }

      while (x != y) {
        x = (x - (logk(x) > 0 ? u[logk(x) - 1] : 0) - 1) / k +
            (logk(x) > 1 ? u[logk(x) - 2] : 0) + 1;
        y = (y - (logk(y) > 0 ? u[logk(y) - 1] : 0) - 1) / k +
            (logk(y) > 1 ? u[logk(y) - 2] : 0) + 1;
        ++c, ++c;
      }

      cout << c << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

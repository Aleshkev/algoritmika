#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef pair<I, I> II;

I f_search(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    if (I mid = (lo + hi) / 2; f(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  []() {
    I n, k;
    cin >> n >> k;

    vector<I> v(n);
    for (I i = 0; i < n; ++i) cin >> v[i];

    auto scan = [&](I x) {
      II w_2, w_1, w_0;  // w_j = d[i - j]
      for (I i = 0; i < n; ++i) {
        w_2 = w_1, w_1 = w_0;
        w_0 = max(w_1, {w_2.first + v[i] - x, w_2.second + 1});
      }
      return II{w_0.first + x * w_0.second, w_0.second};
    };

    if (auto p = scan(0); p.second <= k) {
      cout << p.first << "\n";
      return;
    }

    I max_x = *max_element(v.begin(), v.end()) + 10;

    I x_1 = f_search(0, max_x, [&](I x) { return scan(x).second > k; });
    II p_1 = scan(x_1);

    if (p_1.second == k) {
      cout << p_1.first << "\n";
      return;
    }

    I x_2 = x_1 - 1;
    II p_2 = scan(x_2);

    cout << p_1.first + (p_2.first - p_1.first) * (k - p_1.second) /
                            (p_2.second - p_1.second)
         << "\n";
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

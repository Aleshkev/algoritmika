#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
const I inf = 1e9;

I f_lower_bound(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (f(mid)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> nums(n);
  for (I &i : nums) cin >> i;

  vector<I> sorted = nums;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  for (I &i : nums)
    i = lower_bound(sorted.begin(), sorted.end(), i) - sorted.begin();

  vector<vector<I>> low(n + 1);
  vector<vector<I>> pref(n + 1);
  low[0].push_back(-1);
  pref[0].push_back(1);

  for (I num : nums) {
    // Największy x taki, że low[x][-1] < num.
    auto x_cmp = [&](I i) {
      return (low[i].empty() ? inf : low[i].back()) < num;
    };
    I x = f_lower_bound(1, n + 1, x_cmp) - 1;
    I y = x + 1;
    // I x = 0;
    // for (x = 1; x <= n && !low[x].empty() && low[x].back() < num; ++x)
    //   ;
    // I y = x;
    // --x;

    // Największe d takie, że low[x][d] < num
    assert(low[x].size() > 0);
    auto d_cmp = [&](I i) { return low[x][i] >= num; };
    I d = f_lower_bound(0, low[x].size(), d_cmp);
    // I d = 0;
    // for (d = 0; d < low[x].size() && low[x][d] >= num; ++d)
    //   ;

    I w = (m + pref[x].back() - (d > 0 ? pref[x][d - 1] : 0)) % m;

    low[y].push_back(num);
    pref[y].push_back(pref[y].empty() ? w : (pref[y].back() + w) % m);
  }

  for (I i = n; i >= 1; --i) {
    if (!low[i].empty()) {
      cout << pref[i].back() << '\n';
      break;
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

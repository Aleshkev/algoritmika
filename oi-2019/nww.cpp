#include <bits/stdc++.h>
using namespace std;
typedef uint64_t u64;

u64 naydi(u64 lo, u64 hi, function<bool(u64)> f) {
  while (lo < hi) {
    u64 mid = (lo + hi) / 2;
    if (f(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}

constexpr u64 lim = 1e18, inf = 5e18;

u64 safe_mul(u64 a, u64 b) {
  if (max(a, b) >= inf || a > inf / b) return inf;
  return a * b;
}
u64 safe_lcm(u64 a, u64 b) {
  if (max(a, b) >= inf) return inf;
  return safe_mul(a / gcd(a, b), b);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  map<u64, pair<u64, u64>> long_ones;
  for (u64 a = 1; a < 50000; ++a) {
    u64 x = safe_lcm(safe_lcm(a, a + 1), a + 2);
    for (u64 b = a + 3;; ++b) {
      x = safe_lcm(x, b);
      if (x > lim) break;
      if (long_ones.count(x)) continue;
      long_ones[x] = {a, b};
    }
  }

  u64 n;
  cin >> n;
  for (u64 i = 0; i < n; ++i) {
    u64 x;
    cin >> x;

    vector<pair<u64, u64>> nayden;

    auto a = naydi(1, min<u64>(x, 1e9),
                   [=](u64 a) { return a * (a + 1) * (a + 2) < x; });
    if (lcm(lcm(a, a + 1), a + 2) == x) nayden.emplace_back(a, a + 2);

    auto b = naydi(1, min<u64>(x, 1e9),
                   [=](u64 b) { return b * (b + 1) * (b + 2) / 2 < x; });
    if (lcm(lcm(b, b + 1), b + 2) == x) nayden.emplace_back(b, b + 2);

    auto c = naydi(1, min<u64>(x, 1e9), [=](u64 c) { return c * (c + 1) < x; });
    if (lcm(c, c + 1) == x) nayden.emplace_back(c, c + 1);

    if (long_ones.count(x)) nayden.push_back(long_ones[x]);

    if (nayden.empty()) {
      cout << "NIE\n";
    } else {
      auto p = *min_element(nayden.begin(), nayden.end());
      cout << p.first << " " << p.second << "\n";
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

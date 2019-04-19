#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<II> v(n);
  for (auto &i : v) cin >> i.first >> i.second;
  sort(v.begin(), v.end(), [&](const II &l, const II &r) {
    return l.first - l.second > r.first - r.second;
  });
  I c = 0;
  for (I j = 0; j < n; ++j) {
    c += v[j].first * j + v[j].second * (n - j - 1);
  }
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
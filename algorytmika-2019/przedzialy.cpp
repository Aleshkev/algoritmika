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
  for (I i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end(), [&](II a, II b) {
    return tie(a.second, a.first) < tie(b.second, b.first);
  });

  I c = 0;
  I max_second = 0;
  for (I i = 0; i < n; ++i) {
    if (v[i].first < max_second) continue;
    ++c;
    max_second = v[i].second;
  }

  cout << c << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

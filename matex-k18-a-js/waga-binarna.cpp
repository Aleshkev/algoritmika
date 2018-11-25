#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;
typedef pair<i32, i32> p32;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  i32 n;
  cin >> n;

  vector<p32> v(n);
  for (auto &i : v) cin >> i.first >> i.second;

  sort(v.begin(), v.end(), [](const p32 &l, const p32 &r) {
    i64 lb = (i64(l.first) << i64(10) >> i64(l.second)),
        rb = (i64(r.first) << i64(10) >> i64(r.second));
    return (lb != rb ? lb < rb : l < r);
  });

  for (auto &i : v) cout << i.first << ' ' << i.second << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

struct pt {
  I x, y;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<pt> pts(n);
  for (auto &p : pts) cin >> p.x >> p.y;

  sort(pts.begin(), pts.end(),
       [&](const pt &l, const pt &r) { return l.x < r.x; });

  vector<I> v(n, 1);
  for (I i = 1; i < n; ++i) {
    for (I j = 0; j < i; ++j) {
      if (pts[j].y - (pts[i].x - pts[j].x) <= pts[i].y &&
          pts[i].y <= pts[j].y) {
        v[i] = max(v[i], v[j] + 1);
      }
    }
  }

  cout << *max_element(v.begin(), v.end()) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

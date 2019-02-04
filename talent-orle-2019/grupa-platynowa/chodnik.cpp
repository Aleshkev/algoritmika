#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  map<I, vector<I>> by_x, by_y;
  for (I i = 0; i < n; ++i) {
    I x, y;
    cin >> x >> y;
    by_x[x].push_back(y), by_y[y].push_back(x);
  }

  for (auto &i : by_x) sort(i.second.begin(), i.second.end());
  for (auto &i : by_y) sort(i.second.begin(), i.second.end());

  I p;
  cin >> p;
  for (I i = 0; i < p; ++i) {
    I x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    I c = 0;
    auto &x1_v = by_x[x1], &y1_v = by_y[y1], &x2_v = by_x[x2], &y2_v = by_y[y2];
    c += upper_bound(x1_v.begin(), x1_v.end(), y2) -
         lower_bound(x1_v.begin(), x1_v.end(), y1);
    c += upper_bound(x2_v.begin(), x2_v.end(), y2) -
         lower_bound(x2_v.begin(), x2_v.end(), y1);
    c += upper_bound(y1_v.begin(), y1_v.end(), x2 - 1) -
         lower_bound(y1_v.begin(), y1_v.end(), x1 + 1);
    c += upper_bound(y2_v.begin(), y2_v.end(), x2 - 1) -
         lower_bound(y2_v.begin(), y2_v.end(), x1 + 1);

    cout << c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, l, m;
  cin >> n >> l >> m;

  vector<I> best(n);
  vector<string> current(n);
  map<string, set<I>> by_cars;
  for (I i = 0; i < n; ++i) {
    cin >> current[i];
    by_cars[current[i]].insert(i);
  }

  auto update = [&](const set<I> &v) {
    for (auto i : v) best[i] = max(best[i], (I)v.size());
  };
  for (auto &k : by_cars) update(k.second);

  for (I i = 0; i < m; ++i) {
    I p_1, w_1, p_2, w_2;
    cin >> p_1 >> w_1 >> p_2 >> w_2;
    --p_1, --w_1, --p_2, --w_2;
    by_cars[current[p_1]].erase(p_1), by_cars[current[p_2]].erase(p_2);
    swap(current[p_1][w_1], current[p_2][w_2]);
    by_cars[current[p_1]].insert(p_1), by_cars[current[p_2]].insert(p_2);
    update(by_cars[current[p_1]]), update(by_cars[current[p_2]]);
  }

  for (I i = 0; i < n; ++i) cout << best[i] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
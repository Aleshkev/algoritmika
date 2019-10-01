#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;
typedef pair<I, I> II;

vector<I> pack_to_zero(const vector<I> &v) {
  I n = v.size();

  // Najbardziej profesjonalna optymalizacja.
  for (I i = 0; i < n; ++i)
    if (v[i] == 0) return {v[i]};
  for (I i = 0; i < n; ++i)
    for (I j = i + 1; j < n; ++j)
      if (v[i] + v[j] == 0) return {v[i], v[j]};
  for (I i = 0; i < n; ++i)
    for (I j = i + 1; j < n; ++j)
      for (I k = j + 1; k < n; ++k)
        if (v[i] + v[j] + v[k] == 0) return {v[i], v[j], v[k]};

  vector<unordered_map<I, I>> backpack(n + 1);
  backpack[0][0] = 0;

  for (I i = 1; i <= n; ++i) {
    I weight = v[i - 1];

    for (I y = i - 1; y >= 0; --y) {
      for (II p : backpack[y]) {
        I x = p.first;
        backpack[y + 1][x + weight] = weight;
      }
    }
  }

  I best_y = -1;
  for (I y = 0; y <= n; ++y)
    if (backpack[y].find(0) != backpack[y].end()) best_y = y;
  if (best_y == -1) return {};  // Jak fajnie byłoby mieć for-else w C++...

  vector<I> r;
  for (I y = best_y, x = 0; y > 0; x -= backpack[y][x], y--)
    r.push_back(backpack[y][x]);
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  []() {
    I n, a;
    cin >> n >> a;

    vector<I> v(n);
    for (I &i : v) cin >> i;
    for (I &i : v) i -= a;

    auto r = pack_to_zero(v);
    if (r.empty()) {
      cout << "NIE\n";
    } else {
      cout << "TAK\n" << r.size() << "\n";
      for (I i : r) cout << a + i << " ";
      cout << "\n";
    }
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef pair<I, I> II;

// Dziękuję Mikołaju za pomoc \o

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m, o;
  cin >> n >> m >> o;

  multiset<II> rooms;
  for (I i = 0; i < n; ++i) {
    I cost, volume;
    cin >> cost >> volume;
    rooms.insert({volume, cost});
  }

  vector<II> offers;
  for (I i = 0; i < m; ++i) {
    I value, volume;
    cin >> value >> volume;
    offers.push_back({-value, volume});
  }
  sort(offers.begin(), offers.end());

  vector<I> v;
  for (I i = 0; i < m; ++i) {
    I value = -offers[i].first, needed_volume = offers[i].second;

    auto first_available = rooms.upper_bound({needed_volume, -1});
    if (first_available == rooms.end()) continue;

    I cost = first_available->second;
    v.push_back(value - cost);

    rooms.erase(first_available);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  I c = 0;
  for (I i = 0; i < v.size() && i < o && v[i] > 0; ++i) c += v[i];
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

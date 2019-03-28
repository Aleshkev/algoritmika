#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    o << *i;
    if (i != prev(v.end())) o << ", ";
  }
  o << "]";
  return o;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I w, h, n;
  cin >> w >> h >> n;

  vector<II> v(n);
  for (II &i : v) cin >> i.first >> i.second;

  vector<vector<II>> graph(n);
  for (I i = 0; i < n; ++i) {
    for (I j = 0; j < n; ++j) {
      if (i == j) continue;
      graph[i].push_back({j, (1 << max(abs(v[j].first - v[i].first),
                                       abs(v[j].second - v[i].second)))});
    }
  }

  set<II, greater<II>> q = {{0, 0}};
  vector<I> distance(n);
  distance[0] = 0;

  // vector<I> abstand(n, inf);
  // set<II, greater<II>> q;
  // q.insert({0, hunde[0].x});
  // abstand[hunde[0].x] = 0;
  while (!q.empty()) {
    I d, i;
    tie(d, i) = *q.begin(), q.erase(q.begin());
    distance[i] = d;

    // cout << d << ' ' << i << '\n';

    for (II k : graph[i]) {
      if (d + k.first < distance[k.second]) {
        auto it = q.find({distance[k.second], k.second});
        if (it != q.end()) q.erase(it);
        distance[k.second] = d + k.first;
        q.insert({d + k.first, k.second});
      }
    }
  }

  cout << distance[n - 1] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

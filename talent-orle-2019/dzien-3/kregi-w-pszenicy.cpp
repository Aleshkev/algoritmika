#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef long double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I a_x, a_y, a_n;
  cin >> a_x >> a_y >> a_n;
  vector<I> a_rs(a_n);
  for (I &i : a_rs) cin >> i;

  I b_x, b_y, b_n;
  cin >> b_x >> b_y >> b_n;
  vector<I> b_rs(b_n);
  for (I &i : b_rs) cin >> i;

  I dx2 = (a_x - b_x) * (a_x - b_x), dy2 = (a_y - b_y) * (a_y - b_y);
  I d = floor(sqrt(F(dx2 + dy2)));
  d = (d * d == dx2 + dy2 ? 2 * d : 2 * d + 1);

  for (I &i : a_rs) i *= 2;
  for (I &i : b_rs) i *= 2;

  I nodes = 2 * (a_n + b_n), edges = nodes;

  vector<vector<I>> graph(a_n + b_n);

  vector<I> partial(b_n);
  for (I a_i = 0; a_i < a_n; ++a_i) {
    I a_r = a_rs[a_i];

    I i = lower_bound(b_rs.begin(), b_rs.end(), abs(d - a_r)) - b_rs.begin();
    I j = upper_bound(b_rs.begin() + i, b_rs.end(), a_r + d) - b_rs.begin();

    if (j - i == 0) continue;

    nodes += 2 * (j - i);
    edges += 4 * (j - i);
    if (d - b_rs[i] == a_r || a_r - b_rs[i] == d) {
      nodes -= 3;
      edges -= 4;
    }
    if (b_rs[j - 1] == a_r + d) {
      nodes -= 3;
      edges -= 4;
    }

    graph[a_i].push_back(a_n + i);
    graph[a_n + i].push_back(a_i);
    ++partial[i];
    --partial[j - 1];
  }

  vector<I> pref(b_n);
  partial_sum(partial.begin(), partial.end(), pref.begin());

  for (I i = 0; i < b_n - 1; ++i) {
    if (pref[i] > 0) {
      graph[a_n + i + 1].push_back(a_n + i);
      graph[a_n + i].push_back(a_n + i + 1);
    }
  }

  I k = 0;
  {
    vector<bool> visited(a_n + b_n);
    for (I i = 0; i < a_n + b_n; ++i) {
      if (visited[i]) continue;
      visited[i] = true;
      ++k;

      vector<I> dfs = {i};
      while (!dfs.empty()) {
        I current = dfs.back();
        dfs.pop_back();

        for (I other : graph[current]) {
          if (visited[other]) continue;
          visited[other] = true;
          dfs.push_back(other);
        }
      }
    }
  }

  cout << k + edges - nodes << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

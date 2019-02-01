#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k;
  cin >> n >> k;

  vector<vector<I>> graph(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  I d = 0;
  auto farthest = [&](I origin) {
    I far = origin;

    vector<I> distance(n, inf);
    distance[origin] = 0;
    vector<I> dfs = {origin};

    while (!dfs.empty()) {
      I i = dfs.back();
      dfs.pop_back();

      if (distance[i] > distance[far]) far = i;

      for (I j : graph[i]) {
        if (distance[j] < inf) continue;
        distance[j] = distance[i] + 1;
        dfs.push_back(j);
      }
    }
    d = distance[far];
    return far;
  };

  I a = farthest(0), b = farthest(a);

  cout << (n - 1) * 2 - d + 1 << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

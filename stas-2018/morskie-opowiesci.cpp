#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
const I inf = (1 << 30);
typedef pair<I, I> II;

struct Query {
  I i, b, k;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m, q;
  cin >> n >> m >> q;

  vector<vector<I>> graph(2 * n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(n + b);
    graph[b].push_back(n + a);
    graph[n + b].push_back(a);
    graph[n + a].push_back(b);
  }

  vector<vector<Query>> queries(n);
  for (I i = 0; i < q; ++i) {
    I a, b, k;
    cin >> a >> b >> k;
    --a, --b;
    queries[a].push_back({i, b, k});
  }
  vector<bool> answers(q);

  for (I i = 0; i < n; ++i) {
    vector<I> distance(2 * n, inf);
    deque<I> bfs = {i};
    distance[i] = 0;

    while (!bfs.empty()) {
      I current = bfs.front();
      bfs.pop_front();

      for (I j : graph[current]) {
        if (distance[j] < inf) continue;
        distance[j] = distance[current] + 1;
        bfs.push_back(j);
      }
    }
    for (auto &query : queries[i]) {
      answers[query.i] = (!graph[i].empty() &&
                          distance[n * (query.k % 2) + query.b] <= query.k);
    }
  }

  for (bool i : answers) cout << (i ? "TAK" : "NIE") << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

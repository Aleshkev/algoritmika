#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Edge {
  I i, a, b;
  bool used, reversed;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  []() {
    I m;
    cin >> m;

    I n = 0;
    vector<Edge> edges(m);
    for (I i = 0; i < m; ++i) edges[i].i = i;
    for (Edge &e : edges) {
      cin >> e.a >> e.b;
      n = max({n, e.a, e.b});
      --e.a, --e.b;
    }

    vector<vector<I>> graph(n);
    for (Edge &e : edges) {
      graph[e.a].push_back(e.i), graph[e.b].push_back(e.i);
    }

    for (I i = 0; i < n; ++i) {
      if (graph[i].size() % 2 != 0) {
        cout << "NIE" << '\n';
        return;
      }
    }

    auto force_walk = [&](Edge &e, I from) {
      if (e.b == from) e.reversed = true;
      e.used = true;
      return (e.a == from ? e.b : e.a);
    };

    auto dfs = [&](I start) {
      for (;;) {
        I i = start;
        do {
          while (!graph[i].empty() && edges[graph[i].back()].used)
            graph[i].pop_back();

          if (graph[i].empty()) return;

          i = force_walk(edges[graph[i].back()], i);
        } while (i != start);
      }
    };

    for (I i = 0; i < n; ++i) {
      dfs(i);
    }

    cout << "TAK" << '\n';
    for (Edge &e : edges) {
      cout << (e.reversed ? 'Z' : 'O') << '\n';
    }
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

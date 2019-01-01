#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Edge {
  I i, a, b;
  bool used = false;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  []() {
    I n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (I i = 0; i < m; ++i) {
      Edge e;
      e.i = edges.size();
      bool x, y;
      cin >> e.a >> e.b >> x >> y;
      --e.a, --e.b;
      if (x ^ y) edges.push_back(e);
    }
    m = edges.size();

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

    vector<vector<I>> paths;

    auto dfs = [&](I start) {
      for (;;) {
        I i = start;
        paths.emplace_back();
        do {
          while (!graph[i].empty() && edges[graph[i].back()].used)
            graph[i].pop_back();
          if (graph[i].empty()) return;

          Edge &e = edges[graph[i].back()];
          e.used = true;

          i = (e.a == i ? e.b : e.a);
          paths.back().push_back(i);
        } while (i != start);
      }
    };
    for (I i = 0; i < n; ++i) {
      dfs(i);
    }

    // This turned out more convoluted than I thought it would.
    vector<vector<I>> real_paths;
    vector<bool> met(n);
    for (auto &v : paths) {
      if (v.empty()) continue;

      vector<I> u;
      for (I i = 0; i < v.size(); ++i) {
        if (met[v[i]]) {
          vector<I> w;

          while (!u.empty() && u.back() != v[i]) {
            w.push_back(u.back());
            met[u.back()] = false;
            u.pop_back();
          }
          w.push_back(u.back());

          reverse(w.begin(), w.end());
          real_paths.push_back(w);
        } else {
          u.push_back(v[i]);
        }
        met[v[i]] = true;
      }
      real_paths.push_back(u);

      for (I i : v) met[i] = false;
    }

    cout << real_paths.size() << '\n';
    for (vector<I> &v : real_paths) {
      cout << v.size() << ' ';
      for (I i : v) cout << i + 1 << ' ';
      cout << v.front() + 1 << '\n';
    }
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

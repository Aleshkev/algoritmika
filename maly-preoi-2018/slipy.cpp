#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<string> names(n);
  for (string &i : names) cin >> i;
  sort(names.begin(), names.end());

  vector<vector<bool>> has_edge(n, vector<bool>(n, true));
  for (I i = 0; i < m; ++i) {
    string a, x, b;
    cin >> a >> x >> x >> b;
    I a_i = lower_bound(names.begin(), names.end(), a) - names.begin();
    I b_i = lower_bound(names.begin(), names.end(), b) - names.begin();
    has_edge[a_i][b_i] = has_edge[b_i][a_i] = false;
  }

  // Przez n-ty wierzchołek przechodzą krawędzie między nieparzystymi
  // wierzchołkami.
  vector<vector<I>> graph(n + 1), edge_index(n + 1);
  I n_edges = 0;
  auto add_edge = [&](I a, I b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
    edge_index[a].push_back(n_edges);
    edge_index[b].push_back(n_edges++);
  };
  for (I i = 0; i < n; ++i) {
    for (I j = i + 1; j < n; ++j) {
      if (has_edge[i][j]) add_edge(i, j);
    }
  }

  // Wierzchołki z nieparzystym stopniem.
  vector<I> odd_vertices;
  for (I i = 0; i < n; ++i) {
    if (graph[i].size() % 2 == 1) {
      odd_vertices.push_back(i);
    }
  }
  I n_odd_vertices = odd_vertices.size();

  // Krawędzie między parami wierzchołków z nieparzystym stopniem.
  for (I i = 0; i < n_odd_vertices; i += 2) {
    add_edge(odd_vertices[i], n);
    add_edge(n, odd_vertices[i + 1]);
  }

  vector<bool> used(n_edges);
  vector<I> euler;

  function<void(I)> find_euler = [&](I i) {
    while (!graph[i].empty()) {
      I j = graph[i].back();
      graph[i].pop_back();
      I e = edge_index[i].back();
      edge_index[i].pop_back();
      if (!used[e]) {
        used[e] = true;
        find_euler(j);
        euler.push_back(i);
      }
    }
  };
  find_euler(0);

  cout << n_odd_vertices << '\n';
  for (I i = 0; i < euler.size(); ++i) {
    I j = (i + 1) % euler.size();
    if (euler[i] == n || euler[j] == n) continue;
    cout << names[euler[i]] << ' ' << names[euler[j]] << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
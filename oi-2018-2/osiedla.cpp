/*
                              osiedla.cpp (osiedla) - Code::Blocks 16.01
_______________________________________________________________________________
 File | Edit | View | Search | Tools | Plugins | Settings | Help
/////////////////////////////////////|------------------------------|//////////
[ s] [ d] [ n]  [ f]  [ d]  [  z  [ c| Find broken files in project |d]
[<global>        v] [operator<<(ostre|  --------------------------- |   ]
/////////////////////////////////////| Source formatter...          |//////////
Projects|________|__  |--------------|  --------------------------- |
 v Workspace     |    | C::B TETRIS  | C::B Games                 > |
   > osiedla-brut|    |              |______________________________|
   v osiedla     |    | C::B Snake   |
     v Sources   |    |______________|
        osiedla.c|    _____________________
                 |   |                    | Score: 1902
                 |   |                    | Time: 4h 51min
                 |   |                    |
                 |   |           ██       |
                 |   |           ██       |
                 |   |           ████     |
                 |   |           ████     |
                 |   |██           ██     |
                 |   |██           ██     |
                 |   |██                  |
                 |   |██    ██            |
                 |   |██    ██            |
                 |   |██    ██            |
                 |   |████  ██            |
                 |   |████████      ██████|
                 |   |████████████████  ██|
                 |   |=====================
*/

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

I count_neighborhoods(const vector<vector<I>> &graph) {
  I n = graph.size();

  vector<I> order;
  {
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;

        dfs(j);
      }
      order.push_back(i);
    };

    for (I i = 0; i < n; ++i) {
      if (visited[i]) continue;
      visited[i] = true;
      dfs(i);
    }

    reverse(order.begin(), order.end());
  }

  vector<vector<I>> transposed(n);
  for (I i = 0; i < n; ++i) {
    for (I j : graph[i]) {
      transposed[j].push_back(i);
    }
  }

  I k = 0;
  {
    vector<bool> visited(n);

    function<void(I)> dfs = [&](I i) {
      for (I j : transposed[i]) {
        if (visited[j]) continue;
        visited[j] = true;

        dfs(j);
      }
    };

    for (I origin : order) {
      if (visited[origin]) continue;
      visited[origin] = true;
      dfs(origin);

      ++k;
    }
  }
  return k;
}

struct Edge {
  I target, i;
  bool right;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  I n, m;
  cin >> n >> m;
  vector<vector<Edge>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;

    graph[a].push_back({b, i, true});
    graph[b].push_back({a, i, false});
  }
  vector<bool> edge_used(m), edge_right(m);
  vector<bool> visited(n);

  vector<vector<I>> directed(n);

  function<void(I)> dfs = [&](I i) {
    for (Edge e : graph[i]) {
      if (edge_used[e.i]) continue;
      edge_used[e.i] = true;

      directed[i].push_back(e.target);

      edge_right[e.i] = e.right;

      if (visited[e.target]) continue;
      visited[e.target] = true;

      dfs(e.target);
    }
  };

  for (I i = 0; i < n; ++i) {
    if (visited[i]) continue;
    visited[i] = true;
    dfs(i);
  }

  cout << count_neighborhoods(directed) << '\n';
  for (I i = 0; i < m; ++i) {
    cout << (edge_right[i] ? '>' : '<');
  }
  cout << '\n';

  return 0;
}
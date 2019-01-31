#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<I>> graph(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<vector<I>> children(n);
  vector<I> parent(n);
  vector<I> order;
  {
    vector<bool> visited(n, false);
    vector<I> q = {0};
    parent[0] = -1;
    visited[0] = true;

    while (!q.empty()) {
      I i = q.back();
      q.pop_back();

      for (I j : graph[i]) {
        if (visited[j]) continue;

        visited[j] = true;
        q.push_back(j);

        children[i].push_back(j);
        parent[j] = i;
      }
    }
  }

  vector<bool> win_subtree(n), win_supertree(n);
  win_supertree[0] = true;  // To make ||!x neutral

  {
    function<void(I)> bfs = [&](I i) {
      bool any_losing = false;
      for (I j : children[i]) {
        bfs(j);
        any_losing = (any_losing || !win_subtree[j]);
      }
      win_subtree[i] = any_losing;
    };
    bfs(0);
  }

  {
    function<void(I)> bfs = [&](I i) {
      I losing = 0, losing_j = -1;

      if (parent[i] != -1 && !win_supertree[i]) {
        ++losing;
      }
      for (I j : children[i]) {
        if (!win_subtree[j]) ++losing, losing_j = j;
      }

      for (I j : children[i]) {
        if (losing == 0) {
          win_supertree[j] = false;
        } else if (losing == 1) {
          win_supertree[j] = (j != losing_j);
        } else {
          win_supertree[j] = true;
        }

        bfs(j);
      }
    };
    bfs(0);
  }

  for (I i = 0; i < n; ++i) {
    cout << (win_subtree[i] || !win_supertree[i] ? "Partycja" : "Bajtek")
         << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

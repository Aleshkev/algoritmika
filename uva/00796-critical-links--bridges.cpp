#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
#define pI PRIiMAX
typedef pair<I, I> II;

int main() {
  for (;;) {
    I n;
    if (scanf("%" pI, &n) < 1) break;

    vector<vector<I>> graph(n);

    for (I i = 0; i < n; ++i) {
      I a, m;
      // Seriously, WHY PUT PARENTHESES IN THE INPUT?! WHYYY?!
      scanf("%" pI " (%" pI ")", &a, &m);

      for (I j = 0; j < m; ++j) {
        I b;
        scanf("%" pI, &b);

        graph[a].push_back(b);
      }
    }

    vector<II> bridges;

    // Somewhat-elegant algorithm to find bridges.
    // ===

    vector<I> dfs_parent(n), dfs_preorder(n), dfs_low(n);
    I current_preorder = 0;
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I u) {
      dfs_preorder[u] = dfs_low[u] = current_preorder++;
      for (I v : graph[u]) {
        if (!visited[v]) {
          visited[v] = true;
          dfs_parent[v] = u;

          dfs(v);

          if (dfs_low[v] > dfs_preorder[u]) {
            bridges.push_back(minmax(u, v));
          }

          dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
          dfs_low[u] = min(dfs_low[u], dfs_preorder[v]);
        }
      }
    };
    for (I root = 0; root < n; ++root) {
      if (visited[root]) continue;

      dfs_parent[root] = -1;
      visited[root] = true;
      dfs(root);
    }

    sort(bridges.begin(), bridges.end());

    printf("%" pI " critical links\n", bridges.size());
    for (II ab : bridges) {
      printf("%" pI " - %" pI "\n", ab.first, ab.second);
    }
    printf("\n");  // Some day, I'll find the person who considered
                   // "Presentation errors" a good idea.
  }

  return 0;
}

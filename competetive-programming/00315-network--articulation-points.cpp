// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
#define pI PRIiMAX

int main() {
  // AGHH, it's another of these problems where half of the difficulty is
  // finding arcane ways of using scanf() >:(
  for (;;) {
    I n;
    scanf("%" pI, &n);
    if (n == 0) break;

    vector<vector<I>> graph(n);

    for (;;) {
      I a;
      scanf("%" pI, &a);
      if (a == 0) break;
      --a;

      for (;;) {
        I b;
        char c;
        scanf("%" pI "%c", &b, &c);
        --b;

        graph[a].push_back(b);
        graph[b].push_back(a);

        if (c == '\n') break;
      }
    }

    // Somewhat-elegant algorithm for finding articulation points. Easily
    // modifiable to also find bridges.
    // ===

    vector<I> dfs_parent(n), dfs_preorder(n), dfs_low(n);
    I root = 0, root_dfs_children = 0;
    vector<bool> is_articulation_point(n);

    vector<bool> visited(n);
    I current_preorder = 0;
    function<void(I)> dfs = [&](I u) {
      dfs_preorder[u] = dfs_low[u] = current_preorder++;

      for (I v : graph[u]) {
        if (!visited[v]) {
          visited[v] = true;
          dfs_parent[v] = u;
          if (u == root) ++root_dfs_children;

          dfs(v);

          if (dfs_low[v] >= dfs_preorder[u]) {
            is_articulation_point[u] = true;
          }
          // If we did need to check whether u -> v is a bridge, we could do
          // if (dfs_low[v] > dfs_preorder[u]) here.

          dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
          dfs_low[u] = min(dfs_low[u], dfs_preorder[v]);
        }
      }
    };

    visited[root] = true;
    dfs_parent[root] = -1;
    dfs(root);

    is_articulation_point[root] = (root_dfs_children > 1);

    // This problem needs number of articulation points.
    printf("%" pI "\n", count(is_articulation_point.begin(),
                              is_articulation_point.end(), true));
  }

  return 0;
}

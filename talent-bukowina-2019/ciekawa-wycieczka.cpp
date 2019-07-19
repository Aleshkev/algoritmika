#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cout << ([&]() {
    I n, m;
    cin >> n >> m;

    vector<vector<I>> graph(n);
    for (I i = 0; i < m; ++i) {
      I a, b;
      cin >> a >> b;
      graph[a].push_back(b), graph[b].push_back(a);
    }

    vector<vector<I>> children(n), backrefs(n);
    vector<I> depth(n), roots, post_order;
    {
      vector<bool> visited(n);
      function<void(I)> dfs = [&](I i) {
        if (visited[i]) return;
        visited[i] = true;

        for (I j : graph[i]) {
          if (visited[j]) {
            if (depth[j] < depth[i] - 1) backrefs[i].push_back(j);
            continue;
          }

          depth[j] = depth[i] + 1;
          children[i].push_back(j);
          dfs(j);
        }

        post_order.push_back(i);
      };

      for (I i = 0; i < n; ++i) {
        if (visited[i]) continue;

        roots.push_back(i);
        dfs(i);
      }
    }

    vector<I> prefix(n);
    for (I i : post_order) {
      for (I j : backrefs[i]) {
        if ((depth[i] - depth[j] + 1) % 2 == 0) {
          return true;  // Jest parzysty cykl od razu.
        }
        ++prefix[i], --prefix[j];
      }
    }

    // Korzystamy z tego, że dwa cykle o nieparzystej długości ze wspólną choć
    // jedną krawędzią tworzą cykl o parzystej długości.
    // Krawędzie w drzewie DFS oznaczamy sobie na ilu nieparzystych cyklach są.
    vector<I> cycles(n);
    for (I i : post_order) {
      cycles[i] = prefix[i];
      for (I j : children[i]) cycles[i] += cycles[j];
    }

    if (*max_element(cycles.begin(), cycles.end()) > 1) return true;

    return false;
  }()
               ? "JEST\n"
               : "BRAK\n");  // Nie wiem czemu formatter tak to wciął :P

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

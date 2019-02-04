#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<map<I, I>> graph(n);

  for (I i = 0; i < m; ++i) {
    I a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    graph[a][b] = graph[b][a] = c;
  }

  I q;
  cin >> q;
  while (q--) {
    I op, a, b;
    cin >> op >> a >> b;
    --a, --b;
    if (op == 1) {
      I c;
      cin >> c;
      graph[a][b] = graph[b][a] = c;
    } else if (op == 2) {
      graph[a].erase(graph[a].find(b));
      graph[b].erase(graph[b].find(a));
    } else if (op == 3) {
      I minimal = inf;
      for (II i : graph[a]) {
        if (i.first == b) minimal = min(minimal, i.second);
        if (graph[b].find(i.first) != graph[b].end()) {
          minimal = min(minimal, i.second + graph[b][i.first]);
        }
      }
      cout << (minimal < inf ? minimal : -1) << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

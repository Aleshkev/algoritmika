#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;
constexpr I inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m, q;
  cin >> n >> m >> q;

  vector<vector<I>> graph(n);
  while (m--) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  while (q--) {
    I a, b;
    cin >> a >> b;
    --a, --b;

    vector<I> d(n, inf);
    d[a] = 0;
    deque<I> bfs = {a};
    while (!bfs.empty()) {
      I i = bfs.front();
      bfs.pop_front();
      for (I j : graph[i]) {
        if (d[j] < inf) continue;
        d[j] = d[i] + 1;
        bfs.push_back(j);
      }
    }

    if (d[b] == inf)
      cout << -1 << "\n";
    else {
      cout << d[b] << " ";
      vector<I> p;
      I x = b;
      while (x != a) {
        p.push_back(x);
        for (I y : graph[x])
          if (d[y] < d[x]) x = y;
      }
      p.push_back(a);
      reverse(p.begin(), p.end());
      for (I i : p) cout << i + 1 << " ";
      cout << "\n";
    }
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

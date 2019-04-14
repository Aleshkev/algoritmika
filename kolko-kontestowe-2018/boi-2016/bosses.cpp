#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
const I inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  const I max_n = 5000;
  I n;
  cin >> n;

  static vector<I> dependent[max_n];
  for (I i = 0; i < n; ++i) {
    I m;
    cin >> m;
    while (m--) {
      I x;
      cin >> x;
      dependent[--x].push_back(i);
    }
  }

  // Wstawienie tych zmiennych tutaj jest złym pomysłem, trzeba pilnować żeby je
  // resetować.
  static vector<I> tree[max_n];
  static bool visited[max_n];
  I c = 0;
  function<I(I)> dfs = [&](I i) {
    I p = 1;
    for (I j : tree[i]) {
      p += dfs(j);
    }
    c += p;
    return p;
  };

  I min_c = inf;
  for (I i = 0; i < n; ++i) {
    for (I j = 0; j < n; ++j) {
      tree[j].clear();
      visited[j] = false;
    }
    c = 0;

    deque<I> q = {i};
    visited[i] = true;

    while (!q.empty()) {
      I i = q.front();
      q.pop_front();

      for (I j : dependent[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        tree[i].push_back(j);
        q.push_back(j);
      }
    }

    if (count(visited, visited + n, true) != n) {
      continue;
    }

    dfs(i);

    min_c = min(min_c, c);
  }

  cout << min_c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

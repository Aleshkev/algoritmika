#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    cout << *i;
    if (i != prev(v.end())) cout << ", ";
  }
  cout << "]";
  return o;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<I>> graph(2 * n);
  for (I i = 0; i < m; ++i) {
    I a, b, s;
    cin >> a >> b >> s;
    --a, --b;
    if (!s) {
      graph[a].push_back(b);
      graph[n + b].push_back(n + a);
    } else {
      graph[a].push_back(n + b);
      graph[n + b].push_back(a);
    }
  }

  vector<vector<bool>> path(2 * n, vector<bool>(2 * n, false));
  for (I i = 0; i < 2 * n; ++i) {
    auto &visited = path[i];
    visited[i] = true;
    vector<I> dfs = {i};
    while (!dfs.empty()) {
      I current = dfs.back();
      dfs.pop_back();
      for (I other : graph[current]) {
        if (visited[other]) continue;
        visited[other] = true;
        dfs.push_back(other);
      }
    }
  }

  // for (I i = 0; i < 2 * n; ++i) {
  //   cout << i % n << ": ";
  //   cout << path[i] << endl;
  // }

  for (I i = 0; i < n; ++i) {
    I c = -1;
    for (I j = 0; j < n; ++j) {
      if ((path[n + i][j] && path[j][n + i]) ||
          (path[n + i][n + j] && path[n + j][n + i]))
        ++c;
    }
    cout << c << '\n';
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

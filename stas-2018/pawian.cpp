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
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<vector<I>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  const I max_n = 1e5;
  bitset<max_n> b;
  b[0] = 1;

  vector<I> color(n, -1);
  for (I i = 0; i < n; ++i) {
    if (color[i] != -1) continue;

    vector<I> of_color(2);
    color[i] = 0;
    vector<I> dfs = {i};
    while (!dfs.empty()) {
      I current = dfs.back();
      dfs.pop_back();

      ++of_color[color[current]];

      for (I neighbor : graph[current]) {
        if (color[neighbor] != -1) continue;
        color[neighbor] = !color[current];
        dfs.push_back(neighbor);
      }
    }
    b |= (b << of_color[0]) | (b << of_color[1]);
  }

  // cout << b << endl;

  for (I i = n / 2; i <= n; ++i) {
    if (b[i]) {
      cout << i * (n - i) - m << '\n';
      break;
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

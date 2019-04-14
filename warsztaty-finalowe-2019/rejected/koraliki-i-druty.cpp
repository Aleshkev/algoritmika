#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    o << *i;
    if (i != prev(v.end())) o << ", ";
  }
  o << "]";
  return o;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<II>> graph(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    // cout << "read " << a << " " << b << " " << c << endl;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  vector<I> parent(n), weight(n);
  vector<vector<I>> children(n);
  {
    vector<bool> visited(n);
    vector<I> q = {0};
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();
      for (II e : graph[i]) {
        I j, c;
        tie(j, c) = e;
        if (visited[j]) continue;
        visited[j] = true;
        children[i].push_back(j);
        parent[j] = i;
        weight[j] = c;
        q.push_back(j);
      }
    }
  }

  cout << parent << endl;
  cout << weight << endl;
  cout << children << endl;

  for (I m = 0; m < (1 << n >> 1); ++m) {
    vector<I> edges(n);
    for (I i = 1; i < n; ++i) {
      if (m & (1 << i >> 1)) {
        ++edges[i], ++edges[parent[i]];
      }
    }
    vector<I> q;
    for (I i = 0; i < n; ++i) {
      if (edges[i] == 0) q.push_back(i);
    }

    while (!q.empty()) {
      I i = q.back();
      q.pop_back();

      --edges[i];
      --edges[parent[i]], --edges[parent[i]];
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

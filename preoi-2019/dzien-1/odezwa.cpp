#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I f_lower_bound(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (f(mid)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
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
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  auto is_ok = [&](I x) {
    vector<I> connections(n);
    for (I i = 0; i < n; ++i) {
      connections[i] = graph[i].size();
    }

    vector<I> q;
    for (I i = 0; i < n; ++i) {
      if (connections[i] < x) q.push_back(i);
    }
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();

      for (I j : graph[i]) {
        if (connections[j] < x) continue;
        --connections[j];
        if (connections[j] < x) q.push_back(j);
      }
    }

    for (I i = 0; i < n; ++i) {
      if (connections[i] >= x) return true;
    }
    return false;
  };

  cout << f_lower_bound(0, n, is_ok) - 1 << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

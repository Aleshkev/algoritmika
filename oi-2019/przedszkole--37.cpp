#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I lim = 1e9 + 7;

I q_pow(I n, I k) {
  n %= lim;
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k == 2) return n * n % lim;
  I half = q_pow(n, k / 2);
  return half * half % lim * (k % 2 == 1 ? n : 1) % lim;
}

// Grupa 1.
// (Chyba czasami nie działa?)
I solve_force(vector<vector<I>> &graph, I k) {
  I r = 0;

  I n = graph.size();
  vector<I> state(n);
  function<void(I)> check = [&](I i) {
    bool ok = true;
    for (I j : graph[i]) {
      if (j < i && state[j] == state[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      return;
    }

    if (i == n - 1) {
      ++r;
      return;
    }

    for (I c = 1; c <= k; ++c) {
      state[i + 1] = c;
      check(i + 1);
    }
  };
  state[0] = 1;
  check(0);

  return k * r % lim;
}

// Grupa 4.
I solve_cycle(I n, I k) {
  I x = (q_pow(k - 1, n) + lim + (k - 1) * (n % 2 == 0 ? 1 : -1)) % lim;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m, z;
  cin >> n >> m >> z;
  vector<vector<I>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<vector<vector<I>>> components;
  {  // Dzielimy graf na spójne składowe.
    vector<vector<I>> nodes;
    vector<bool> visited(n);
    for (I s = 0; s < n; ++s) {
      if (visited[s]) continue;
      nodes.emplace_back();
      visited[s] = true;
      vector<I> dfs = {s};
      while (!dfs.empty()) {
        I i = dfs.back();
        dfs.pop_back();
        nodes.back().push_back(i);
        for (I j : graph[i]) {
          if (visited[j]) continue;
          visited[j] = true;
          dfs.push_back(j);
        }
      }
    }
    for (auto &v : nodes) {
      sort(v.begin(), v.end());
      components.emplace_back(v.size());
#define local_index(A) (lower_bound(v.begin(), v.end(), A) - v.begin())
      for (I i : v)
        for (I j : graph[i])
          components.back()[local_index(i)].push_back(local_index(j));
    }
  }

  bool is_cycles = true;
  for (auto &v : components)
    for (auto &w : v)
      if (w.size() > 2) is_cycles = false;

  map<I, I> cycle_sizes;
  if (is_cycles)
    for (auto &v : components) ++cycle_sizes[v.size()];

  for (I i = 0; i < z; ++i) {
    I k;
    cin >> k;
    I r = 1;
    if (is_cycles) {
      for (auto [x, y] : cycle_sizes) {
        r *= q_pow(solve_cycle(x, k), y);
        r %= lim;
      }
    } else {
      for (auto &v : components) {
        r *= solve_force(v, k);
        r %= lim;
      }
    }

    cout << r << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

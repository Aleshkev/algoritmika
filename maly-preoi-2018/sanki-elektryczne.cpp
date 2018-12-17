#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

struct E {
  I a, b, w;
};
bool operator<(const E &x, const E &y) { return x.b < y.b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  // 0. Wydajna funkcja do policzenia maksymalnej fajności dla krawędzi jeżeli
  // możemy przejść przez nią dowolną liczbę razy.
  const I pre_lim = 1e5;
  vector<I> pre(pre_lim + 1);
  pre[0] = 0;
  for (I i = 1; i <= pre_lim; ++i) {
    pre[i] = pre[i - 1] + i * (i + 1) / 2;
  }

  auto max_faynosc = [&](I x) {
    if (x == 0) return (I)0;
    I lo = 0, hi = 1e8;
    while (lo < hi) {
      I n = (lo + hi) / 2;
      if (n * n + n < 2 * x) {
        lo = n + 1;
      } else {
        hi = n;
      }
    }
    --lo;
    return x * (lo + 1) - pre[lo];
  };

  I n, m;
  cin >> n >> m;

  // 1. Wczytanie danych.
  vector<E> edges(m);
  vector<vector<I>> graph(n), graph_transposed(n);

  for (E &e : edges) {
    cin >> e.a >> e.b >> e.w;
    --e.a, --e.b;

    graph[e.a].push_back(e.b);
    graph_transposed[e.b].push_back(e.a);
  }
  I player;
  cin >> player;
  --player;

  // 2. Algorytm kogoś-tam na D do znalezienia silnie spójnych składowych.
  vector<I> sequence;
  {
    vector<bool> visited(n, false);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i])
        if (!visited[j]) visited[j] = true, dfs(j);
      sequence.push_back(i);
    };
    for (I i = 0; i < n; ++i) {
      if (!visited[i]) visited[i] = true, dfs(i);
    }

    reverse(sequence.begin(), sequence.end());
  }

  I k = 0;  // Liczba silnie spójnych.
  vector<I> component(n);
  {
    vector<bool> visited(n, false);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph_transposed[i])
        if (!visited[j]) {
          visited[j] = true;
          component[j] = component[i];
          dfs(j);
        }
    };
    for (I i : sequence) {
      if (!visited[i]) {
        visited[i] = true;
        component[i] = k++;
        dfs(i);
      }
    }
  }

  // 3. Policzyć fajność każdej spójnej.
  vector<I> component_faynosc(k);
  vector<vector<E>> dag(k);
  for (E e : edges) {
    if (component[e.a] == component[e.b]) {
      component_faynosc[component[e.a]] += max_faynosc(e.w);
    } else {
      dag[component[e.a]].push_back({component[e.a], component[e.b], e.w});
    }
  }

  for (I i = 0; i < k; ++i) {
    sort(dag[i].begin(), dag[i].end());
    auto v = dag[i];
    dag[i].clear();
    for (I j = 0; j < v.size();) {
      I b = v[j].b, w = v[j].w;
      while (j < v.size() && v[j].b == b) {
        w = max(w, v[j].w), ++j;
      }
      dag[i].push_back({i, b, w});
    }
  }

  // 4. Policzyć ile krawędzi wchodzi do każdej spójnej...
  vector<I> incoming(k);
  for (I i = 0; i < k; ++i) {
    for (E e : dag[i]) {
      ++incoming[e.b];
    }
  }

  // 5. ...żeby móc posortować topologicznie.
  vector<I> coleynosc;
  vector<I> q;
  for (I i = 0; i < k; ++i) {
    if (incoming[i] == 0) q.push_back(i);
  }
  while (!q.empty()) {
    I i = q.back();
    q.pop_back();

    coleynosc.push_back(i);

    for (E e : dag[i]) {
      --incoming[e.b];
      if (incoming[e.b] == 0) {
        q.push_back(e.b);
      }
    }
  }

  // 6. Trzeba ignorować spójne do których Bajtoszek nie dojdzie.
  vector<bool> reachable(k);
  reachable[component[player]] = true;
  for (I i : coleynosc) {
    for (E e : dag[i]) {
      reachable[e.b] = (reachable[e.b] || reachable[i]);
    }
  }

  // 7. Policzyć wreszcie wynik dynamikiem na dagu.
  vector<I> dp(k, 0);
  dp[component[player]] = component_faynosc[component[player]];
  for (I i : coleynosc) {
    if (!reachable[i]) continue;
    for (E e : dag[i]) {
      dp[e.b] = max(dp[e.b], dp[e.a] + component_faynosc[e.b] + e.w);
    }
  }

  // 8. PROFIT.
  cout << *max_element(dp.begin(), dp.end()) << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}
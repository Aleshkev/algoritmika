#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m, k;
  cin >> n >> m >> k;
  vector<I> p(k);
  for (I i = 0; i < k; ++i) {
    cin >> p[i];
    --p[i];
  }

  vector<vector<I>> graph(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b);
  }

  vector<I> order;
  {
    vector<I> incoming(n), q;
    for (I i = 0; i < n; ++i) {
      for (I j : graph[i]) ++incoming[j];
    }
    for (I i = 0; i < n; ++i) {
      if (incoming[i] == 0) q.push_back(i);
    }
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();
      order.push_back(i);
      for (I j : graph[i]) {
        --incoming[j];
        if (incoming[j] == 0) {
          q.push_back(j);
        }
      }
    }
  }
  vector<I> reverse_order(n);
  reverse_copy(order.begin(), order.end(), reverse_order.begin());

  vector<bool> winning(n);
  vector<I> delay(n);

  for (I i : reverse_order) {
    winning[i] = false;
    for (I j : graph[i])
      if (!winning[j]) winning[i] = true;
    if (winning[i]) {
      delay[i] = inf;
      for (I j : graph[i]) delay[i] = min(delay[i], delay[j] + 1);
    } else {
      delay[i] = 0;
      for (I j : graph[i]) delay[i] = max(delay[i], delay[j] + 1);
    }
  }

  I min_win = inf, min_lose = inf;
  for (I i : p) {
    if (winning[i])
      min_win = min(min_win, delay[i]);
    else
      min_lose = min(min_lose, delay[i]);
  }

  cout << (min_win <= min_lose ? "T" : "R") << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  I k = 664571, u = 1e7;
  vector<bool> is_prime(u + 1, true);
  for (I i = 2; i <= u; ++i) {
    if (!is_prime[i]) continue;
    for (I j = i * i; j <= u; j += i) is_prime[j] = false;
  }
  vector<I> primes;
  for (I i = 2; i <= u; ++i) {
    if (is_prime[i]) primes.push_back(i);
  }
  assert(primes.size() >= k);

  auto graph_hash = [&]() {
    vector<vector<I>> graph(n), tree(n);
    for (I i = 0; i < n - 1; ++i) {
      I a, b;
      cin >> a >> b;
      --a, --b;
      graph[a].push_back(b), graph[b].push_back(a);
    }
    {
      vector<bool> visited(n);
      visited[0] = true;
      vector<I> q = {0};
      while (!q.empty()) {
        I i = q.back();
        q.pop_back();
        for (I j : graph[i]) {
          if (visited[j]) continue;
          visited[j] = true;
          tree[i].push_back(j);
          q.push_back(j);
        }
      }
    }
    function<I(I)> dfs = [&](I i) {
      vector<I> child_hashes;
      for (I j : tree[i]) {
        child_hashes.push_back(dfs(j));
      }
      sort(child_hashes.begin(), child_hashes.end());
      I hash = 1;
      for (I x : child_hashes) {
        hash = (hash * primes[x - 1] - 1) % k + 1;
      }
      return hash;
    };
    return dfs(0);
  };

  I a = graph_hash(), b = graph_hash();
  cout << (a == b ? "TAK" : "NIE") << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
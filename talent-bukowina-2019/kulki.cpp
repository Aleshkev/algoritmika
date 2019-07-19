#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

// Ten kod nie jest optymalny.
// Nie działa jeżeli jest taka sytuacja:
//        o
//       / \
//  (A) o   o
//           \
//            o
//             \
//             ... (n wierzchołków)
//               \
//                o
// (Zakładając, że zawsze po lewej jest poddrzewo z mniejszym minimum.)
// Jeżeli na zmianę będzie dodawana kulka (wleci do A) i zabierana z A, ścieżka
// będzie za każdym razem w O(n) przebudowywana, dając złożoność całości na
// O(n²).

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, q;
  cin >> n >> q;

  I max_k = 1;
  while ((1 << max_k) < n + 1) ++max_k;
  vector<vector<I>> ancestors(max_k + 1, vector<I>(n + 1, -1));
  auto &parent = ancestors[0];
  vector<vector<I>> children(n + 1);

  for (I i = 1; i <= n; ++i) {
    I x;
    cin >> x;
    parent[i] = x;
    children[x].push_back(i);
  }

  vector<I> depth(n + 1);
  depth[0] = 0;
  vector<I> subtree_min(n + 1);
  function<void(I)> dfs = [&](I i) {
    subtree_min[i] = i;
    for (auto j : children[i]) {
      depth[j] = depth[i] + 1;
      dfs(j);
      subtree_min[i] = min(subtree_min[i], subtree_min[j]);
    }
    sort(children[i].begin(), children[i].end(),
         [&](I a, I b) { return subtree_min[a] < subtree_min[b]; });
  };
  dfs(0);

  for (I k = 1; k <= max_k; ++k) {
    for (I i = 1; i <= n; ++i) {
      if (ancestors[k - 1][i] == -1) continue;
      ancestors[k][i] = ancestors[k - 1][ancestors[k - 1][i]];
    }
  }

  vector<I> path = {0};
  while (!children[path.back()].empty()) {
    path.push_back(children[path.back()].front());
  }

  vector<bool> filled(n + 1);

  auto first_unfilled_child = [&](I position) {
    for (I i = 0; i < children[position].size(); ++i) {
      if (!filled[children[position][i]]) {
        return children[position][i];
      }
    }
    return (I)-1;
  };

  auto insert_kulechka = [&]() {
    filled[path.back()] = true;
    path.pop_back();

    assert(!path.empty());

    for (;;) {
      I child = first_unfilled_child(path.back());
      if (child != -1)
        path.push_back(child);
      else
        break;
    }
  };

  auto remove_kulechka = [&](I position) {
    I lower = position, c = 0;
    for (I k = max_k; k >= 0; --k) {
      if (ancestors[k][lower] == -1) continue;
      if (filled[ancestors[k][lower]]) {
        c += (1 << k);
        lower = ancestors[k][lower];
      }
    }
    I higher = parent[lower];
    ++c;

    if (path.size() > depth[higher] && path[depth[higher]] == higher &&
        (path.size() == depth[higher] + 1 ||
         subtree_min[lower] < subtree_min[path[depth[lower]]])) {
      while (path.back() != higher) path.pop_back();
      path.push_back(lower);
    }

    filled[lower] = false;

    return c - 1;
  };

  while (q--) {
    I o, m;
    cin >> o >> m;
    if (o == 1) {
      for (I i = 0; i < m; ++i) {
        if (i == m - 1) cout << path.back() << '\n';
        insert_kulechka();
      }
    } else if (o == 2) {
      cout << remove_kulechka(m) << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

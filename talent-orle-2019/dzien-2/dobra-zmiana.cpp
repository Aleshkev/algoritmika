#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  []() {
    I n, m;
    cin >> n >> m;

    vector<vector<I>> graph(n);
    for (I i = 0; i < m; ++i) {
      I a, b;
      cin >> a >> b;
      --a, --b;
      graph[a].push_back(b), graph[b].push_back(a);
    }
    for (auto &i : graph) sort(i.begin(), i.end());

    vector<I> blocked(n);
    for (I i = 0; i < n; ++i) {
      blocked[i] = graph[i].size();
    }
    auto by_blocked = [&](I x, I y) { return blocked[x] < blocked[y]; };

    vector<bool> color(n);
    {
      vector<bool> visited(n);
      vector<I> dfs;
      for (I i = 0; i < n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs.push_back(i);
        while (!dfs.empty()) {
          I i = dfs.back();
          dfs.pop_back();

          for (I j : graph[i]) {
            if (visited[j]) continue;
            visited[j] = true;
            dfs.push_back(j);

            color[j] = !color[i];
          }
        }
      }
    }

    vector<I> l, r;
    for (I i = 0; i < n; ++i) {
      (color[i] == 0 ? l : r).push_back(i);
    }
    if (l.size() % 3 < r.size() % 3) swap(l, r);
    I l_n = l.size(), r_n = r.size();

    vector<I> assigned(n, -1);

    I c = 0;

    if (l_n % 3 != 0) {
      bool ok = false;

      if (!ok) {
        I potential_i = *min_element(r.begin(), r.end(), by_blocked);
        if (blocked[potential_i] <= l_n - 2) {
          assigned[potential_i] = 1, c = 1;
          for (I k : l) {
            if (assigned[k] != -1 ||
                binary_search(graph[k].begin(), graph[k].end(), potential_i))
              continue;
            assigned[k] = 1, ++c;
            if (c == 3) break;
          }

          ok = true;
        }
      }

      if (!ok && l.size() >= 2 && r.size() >= 4) {
        vector<I> potential = l;
        sort(potential.begin(), potential.end(), by_blocked);
        I potential_i = potential[0], potential_j = potential[1];

        I for_j = r_n - blocked[potential_j],
          for_i = r_n - blocked[potential_i], for_ij = r_n - for_j - for_i;

        if (for_i >= 2 && for_j >= 2) {
          assigned[potential_i] = 1, ++c;

          for (I k : r) {
            if (c == 3) break;
            if (assigned[k] != -1 ||
                binary_search(graph[k].begin(), graph[k].end(), potential_i))
              continue;
            assigned[k] = 1, ++c;
          }
          assert(c == 3);

          assigned[potential_j] = 2, ++c;
          for (I k : r) {
            if (c == 6) break;
            if (assigned[k] != -1 ||
                binary_search(graph[k].begin(), graph[k].end(), potential_j))
              continue;
            assigned[k] = 2, ++c;
          }
          assert(c == 6);

          ok = true;
        }
      }

      if (!ok) {
        cout << "NIE" << '\n';
        return;
      }
    }

    for (I i : l) {
      if (assigned[i] != -1) continue;
      assigned[i] = 1 + (c++) / 3;
    }
    for (I i : r) {
      if (assigned[i] != -1) continue;
      assigned[i] = 1 + (c++) / 3;
    }

    cout << "TAK" << '\n';
    for (I i : assigned) cout << i << ' ';
    cout << '\n';
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> n_connected_o(n), s_connected_o(n);  // number of, sum of indices of
  for (I i = 0; i < n; ++i) {
    cin >> n_connected_o[i] >> s_connected_o[i];
    s_connected_o[i] -= n_connected_o[i];  // 0-based indexing is the best.
  }

  vector<I> n_connected = n_connected_o, s_connected = s_connected_o;

  vector<vector<I>> children(n);
  vector<I> parents(n, -1);
  vector<I> q;
  for (I i = 0; i < n; ++i) {
    if (n_connected[i] == 1) q.push_back(i);
  }
  while (!q.empty()) {
    I i = q.back();
    q.pop_back();
    I parent = s_connected[i];

    if (n_connected[i] != 1) {
      continue;
    }
    parents[i] = parent;

    n_connected[i] = s_connected[i] = 0;

    children[parent].push_back(i);
    --n_connected[parent];
    s_connected[parent] -= i;
    if (n_connected[parent] == 1) {
      q.push_back(parent);
    }
  }

  bool ok = true;
  for (I i = 0; i < n; ++i) {
    I s = (parents[i] != -1 ? parents[i] : 0);
    for (I j : children[i]) {
      s += j;
    }
    if (s != s_connected_o[i] ||
        (parents[i] != -1 ? 1 : 0) + children[i].size() != n_connected_o[i]) {
      ok = false;
      break;
    }
  }

  // I think there can't be any ambiguous situation.
  if (ok) {
    cout << "OK\n";
    I m = 0;
    for (I i = 0; i < n; ++i) {
      m += children[i].size();
    }
    cout << m << '\n';
    for (I i = 0; i < n; ++i) {
      for (I j : children[i]) {
        cout << i + 1 << ' ' << j + 1 << '\n';
      }
    }
  } else {
    cout << "NIEMOZLIWE\n";
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

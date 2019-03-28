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

struct Hund {
  I x, p;
};
struct Kante {
  I v, w;
};

ostream &operator<<(ostream &o, Hund i) {
  o << "(" << i.x << ", " << i.p << ")";
  return o;
}
ostream &operator<<(ostream &o, Kante i) {
  o << "(" << i.v << ", " << i.w << ")";
  return o;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<Hund> hunde(m);
  for (I i = 0; i < m; ++i) cin >> hunde[i].x >> hunde[i].p;

  vector<vector<I>> jumps(n);
  for (Hund h : hunde) {
    jumps[h.x].push_back(h.p);
  }
  for (I i = 0; i < n; ++i) {
    sort(jumps[i].begin(), jumps[i].end());
    jumps[i].erase(unique(jumps[i].begin(), jumps[i].end()), jumps[i].end());
  }

  vector<vector<Kante>> graph(n);
  // for (I i = 0; i < m; ++i) {
  //   // for (I j = 0; j < m; ++j) {
  //   //   if (i == j) continue;
  //   //   // if (hunde[i].x == hunde[j].x) {
  //   //   //   graph[i].push_back({j, 0});
  //   //   // }
  //   //   if (hunde[i].x % hunde[i].p == hunde[j].x % hunde[i].p) {
  //   //     graph[hunde[i].x].push_back(
  //   //         {hunde[j].x, abs(hunde[j].x - hunde[i].x) / hunde[i].p});
  //   //   }
  //   // }
  // }

  // cout << jumps << endl;

  for (I i = 0; i < n; ++i) {
    for (I c : jumps[i]) {
      for (I j = i - c; j >= 0; j -= c) {
        if (!jumps[j].empty()) {
          graph[i].push_back({j, (i - j) / c});
          if (binary_search(jumps[j].begin(), jumps[j].end(), c)) break;
        }
      }
      for (I j = i + c; j < n; j += c) {
        if (!jumps[j].empty()) {
          graph[i].push_back({j, (j - i) / c});
          if (binary_search(jumps[j].begin(), jumps[j].end(), c)) break;
        }
      }
    }
  }

  // for (auto i : graph) {
  //   cout << i << endl;
  // }

  vector<I> abstand(n, inf);
  set<II, greater<II>> q;
  q.insert({0, hunde[0].x});
  abstand[hunde[0].x] = 0;
  while (!q.empty()) {
    I d, i;
    tie(d, i) = *q.begin(), q.erase(q.begin());
    abstand[i] = d;

    // cout << d << ' ' << i << '\n';

    for (Kante k : graph[i]) {
      if (d + k.w < abstand[k.v]) {
        auto it = q.find({abstand[k.v], k.v});
        if (it != q.end()) q.erase(it);
        abstand[k.v] = d + k.w;
        q.insert({d + k.w, k.v});
      }
    }
  }

  // cout << abstand << '\n';

  cout << (abstand[hunde[1].x] < inf ? abstand[hunde[1].x] : -1) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

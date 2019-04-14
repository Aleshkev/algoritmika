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

struct circle {
  I x, y, r, i;
};
ostream &operator<<(ostream &o, circle a) {
  o << "(" << a.x << ", " << a.y << ", r = " << a.r << ", [" << a.i << "])";
  return o;
}

bool can_go_between(const circle &a, const circle &b, I d) {
  // cout << "can_go_between(" << a << ", " << b << ", " << r << ")" << endl;
  // cout << pow(a.x - b.x) * (a.y - b.y) << " " << pow(a.r + b.r + r, 2) <<
  // endl;
  return pow(a.x - b.x, 2) + pow(a.y - b.y, 2) >= pow(a.r + b.r + d, 2);
}

I n, m, w, h;
vector<circle> obstacles;

vector<bool> reachable(I d) {  // O(n²), large constant.
  // graph[n..n + 3] = [bottom, right, up, left]
  vector<vector<I>> graph(n + 4);
  auto make_edge = [&](I a, I b) { graph[a].push_back(b); };

  for (auto &a : obstacles) {
    for (auto &b : obstacles) {
      if (&a == &b) continue;
      if (!can_go_between(a, b, d)) {
        make_edge(a.i, b.i);
      }
    }
    if (a.y - a.r - d < 0) make_edge(a.i, n + 0);
    if (a.x + a.r + d > w) make_edge(a.i, n + 1);
    if (a.y + a.r + d > h) make_edge(a.i, n + 2);
    if (a.x - a.r - d < 0) make_edge(a.i, n + 3);
  }

  vector<I> group(n + 4, -1);
  I group_i = 1;
  for (I i = 0; i < n + 4; ++i) {
    if (group[i] != -1) continue;
    vector<I> q = {i};
    group[i] = group_i++;
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();
      for (I j : graph[i]) {
        if (group[j] != -1) continue;
        group[j] = group[i];
        q.push_back(j);
      }
    }
  }

  // for (I i = 0; i < n + 4; ++i) {
  //   cout << i << ": " << graph[i] << endl;
  // }
  // cout << "group: " << group << '\n';

  auto g = [&](I x, I y) { return group[n + x] == group[n + y]; };

  // cout << "reachable(" << d << ") -> "
  //      << vector<I>({!(g(0, 1) || g(0, 2) || g(0, 3)),
  //                    !(g(0, 3) || g(1, 2) || g(0, 2) || g(1, 3)),
  //                    !(g(3, 0) || g(3, 1) || g(3, 2)),
  //                    !(g(1, 0) || g(1, 2) || g(1, 3)),
  //                    !(g(0, 1) || g(2, 3) || g(0, 2) || g(1, 3)),
  //                    !(g(2, 0) || g(2, 1) || g(2, 3))})
  //      << endl;

  return {!(g(0, 1) || g(0, 2) || g(0, 3)),
          !(g(0, 3) || g(1, 2) || g(0, 2) || g(1, 3)),
          !(g(3, 0) || g(3, 1) || g(3, 2)),
          !(g(1, 0) || g(1, 2) || g(1, 3)),
          !(g(0, 1) || g(2, 3) || g(0, 2) || g(1, 3)),
          !(g(2, 0) || g(2, 1) || g(2, 3))};
}

vector<I> min_reachable() {  // O(n² log n), extremely large constant.
  vector<I> c(6);
  for (I i = 0; i < 6; ++i) {
    c[i] = f_lower_bound(0, w + h,
                         [&](I x) {
                           I v = reachable(2 * x)[i];
                           //  cout << "f(" << x << ") = " << v << endl;
                           return v;
                         }) -
           1;
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> n >> m >> w >> h;
  obstacles.resize(n);
  for (I i = 0; i < n; ++i) {
    auto &o = obstacles[i];
    cin >> o.x >> o.y >> o.r;
    o.i = i;
  }
  // cout << reachable(1) << endl;
  vector<I> magic = min_reachable();
  // cout << magic << endl;

  for (I i = 0; i < m; ++i) {
    I r, e;
    cin >> r >> e;
    --e;

    vector<I> ok = {e};
    auto g = [&](I j, I a, I b) {
      if (e == a && r <= magic[j])
        ok.push_back(b);
      else if (e == b && r <= magic[j])
        ok.push_back(a);
    };
    g(0, 0, 1), g(1, 0, 2), g(2, 0, 3);
    g(3, 1, 2), g(4, 1, 3);
    g(5, 2, 3);

    sort(ok.begin(), ok.end());
    // cout << ok << endl;
    for (I i : ok) {
      cout << i + 1;
    }
    cout << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

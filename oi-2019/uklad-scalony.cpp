#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;
const I inf = 1e18;

struct pt {
  I x, y;
  pt(I x = 0, I y = 0) : x(x), y(y) { return; };
};
ostream &operator<<(ostream &o, pt p) {
  return o << "(" << p.x << ", " << p.y << ")";
}

typedef vector<pair<pt, pt>> ans_t;

ans_t solve(I w, I h, I k) {
  vector<pair<pt, pt>> ans;

  I m = 0;
  vector<vector<bool>> taken(w, vector<bool>(h));
  auto is_free = [&](pt a) {
    return 0 <= a.x && a.x < w && 0 <= a.y && a.y < h && !taken[a.x][a.y];
  };
  auto edge = [&](pt a, pt b) {
    ans.emplace_back(a, b);
    taken[b.x][b.y] = true;
  };

  I s = (h - 1) / 2;
  taken[0][s] = true;
  for (I x = 1; x < w; ++x) edge({x - 1, s}, {x, s});
  for (I y = s - 1; y >= 0; --y) edge({w - 1, y + 1}, {w - 1, y});
  for (I y = s + 1; y < h; ++y) edge({0, y - 1}, {0, y});

  if (h % 2 == 0) k = max<I>(k, ans.size() + 1);
  pt last = {w - 1, 0};
  for (I y = 0; y < s && ans.size() < k; ++y)
    if (y % 2 == 0)
      for (I x = w - 2; x >= 0 && ans.size() < k; --x)
        edge(last, {x, y}), last = {x, y};
    else
      for (I x = 0; x <= w - 2 && ans.size() < k; ++x)
        edge(last, {x, y}), last = {x, y};
  last = {0, h - 1};
  for (I y = h - 1; y > s && ans.size() < k; --y)
    if ((h - y - 1) % 2 == 0)
      for (I x = 1; x <= w - 1 && ans.size() < k; ++x)
        edge(last, {x, y}), last = {x, y};
    else
      for (I x = w - 1; x >= 1 && ans.size() < k; --x)
        edge(last, {x, y}), last = {x, y};

  for (I x = 0; x < w; ++x) {
    for (I y = s - 1; y >= 0 && is_free({x, y}); --y) edge({x, y + 1}, {x, y});
    for (I y = s + 1; y < h && is_free({x, y}); ++y) edge({x, y - 1}, {x, y});
  }

  return ans;
}

bool is_length_ok(I w, I h, I k, const ans_t &ans) {
#define at(A) (A.y * w + A.x)

  vector<vector<I>> graph(w * h);
  for (auto p : ans) {
    graph[at(p.first)].push_back(at(p.second));
    graph[at(p.second)].push_back(at(p.first));
  }

  auto distances = [&](I start) {
    vector<I> d(w * h, inf);
    deque<I> bfs = {start};
    d[start] = 0;
    while (!bfs.empty()) {
      I i = bfs.front();
      bfs.pop_front();
      for (I j : graph[i]) {
        if (d[j] < inf) continue;
        d[j] = d[i] + 1;
        bfs.push_back(j);
      }
    }
    return d;
  };

  auto d0 = distances(0);
  I a = max_element(d0.begin(), d0.end()) - d0.begin();

  auto d1 = distances(a);
  I b = max_element(d1.begin(), d1.end()) - d1.begin();
  return d1[b] == k;
}

// void verify(I w, I h, I k, vector<pair<pt, pt>> ans) {
//   if (ans.size() != w * h - 1)
//     cout << "ERR: inadequate #edges: " << ans.size() << ", expected "
//          << w * h - 1 << endl;

//   vector<vector<I>> graph(w * h);
//   for (auto p : ans) {
//     graph[at(p.first)].push_back(at(p.second));
//     graph[at(p.second)].push_back(at(p.first));
//   }

//   auto distances = [&](I start) {
//     vector<I> d(w * h, inf);
//     deque<I> bfs = {start};
//     d[start] = 0;
//     while (!bfs.empty()) {
//       I i = bfs.front();
//       bfs.pop_front();
//       for (I j : graph[i]) {
//         if (d[j] < inf) continue;
//         d[j] = d[i] + 1;
//         bfs.push_back(j);
//       }
//     }
//     return d;
//   };

//   auto d0 = distances(0);
//   I a = max_element(d0.begin(), d0.end()) - d0.begin();

//   auto d1 = distances(a);
//   I b = max_element(d1.begin(), d1.end()) - d1.begin();
//   if (d1[b] != k)
//     cout << "ERR: inadequate longest path: " << d1[b] << ", expected " << k
//          << endl;

//   cout << "verified by VeriCheck (TM)" << endl;
// }

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  []() {
    I w, h, k;
    cin >> w >> h >> k;

    if (w == 1 && h == 1 && k == 0) {
      cout << "TAK\n";
      return;
    } else if (k < w + h - 2 || k > w * h - 1 ||
               (w % 2 == 0 && h % 2 == 0 && k == w + h - 2)) {
      cout << "NIE\n";
      return;
    }

    cout << "TAK\n";

    auto ans_1 = move(solve(w, h, k));
    auto ans_2 = move(solve(h, w, k));
    for (auto &p : ans_2) {
      swap(p.first.x, p.first.y), swap(p.second.x, p.second.y);
    }

    auto &ans = (is_length_ok(w, h, k, ans_1) ? ans_1 : ans_2);

    for (auto &p : ans) {
      cout << p.first.x + 1 << " " << p.first.y + 1 << " " << p.second.x + 1
           << " " << p.second.y + 1 << "\n";
    }

    // verify(w, h, k, ans);
  }();
#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I h, w, t;
  cin >> h >> w >> t;

  auto at = [&](I x, I y) { return y * w + x; };
  vector<I> distance(h * w, inf);
  deque<I> q;
  for (I y = 0; y < h; ++y) {
    string s;
    cin >> s;
    for (I x = 0; x < w; ++x) {
      if (s[x] == 'x') distance[at(x, y)] = 0, q.push_back(at(x, y));
    }
  }

  const vector<I> diff_x = {0, 1, 0, -1}, diff_y = {1, 0, -1, 0};

  while (!q.empty()) {
    I x = q.front() % w, y = q.front() / w;
    q.pop_front();

    for (I i = 0; i < 4; ++i) {
      I dx = x + diff_x[i], dy = y + diff_y[i];
      if (0 <= dx && dx < w && 0 <= dy && dy < h &&
          distance[at(dx, dy)] > distance[at(x, y)] + 1) {
        distance[at(dx, dy)] = distance[at(x, y)] + 1;
        q.push_back(at(dx, dy));
      }
    }
  }

  vector<II> ans;
  for (I y = 0; y < h; ++y) {
    for (I x = 0; x < w; ++x) {
      if (distance[at(x, y)] <= t) ans.emplace_back(y + 1, x + 1);
    }
  }
  cout << ans.size() << '\n';
  for (II i : ans) {
    cout << i.first << ' ' << i.second << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
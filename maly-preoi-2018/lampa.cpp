#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
const I inf = 1e9;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I h, w;
  cin >> h >> w;
  ++h, ++w;

  auto at = [&](I x, I y) { return y * w + x; };

  vector<vector<I>> graph_zero(w * h), graph_one(w * h);
  for (I y = 0; y < h - 1; ++y) {
    string s;
    cin >> s;
    for (I x = 0; x < w - 1; ++x) {
      I a_asc = at(x, y + 1), b_asc = at(x + 1, y);    // ↗
      I a_desc = at(x, y), b_desc = at(x + 1, y + 1);  // ↘
      I a_zero = a_asc, b_zero = b_asc, a_one = a_desc, b_one = b_desc;
      if (s[x] != '/') swap(a_zero, a_one), swap(b_zero, b_one);

      graph_zero[a_zero].push_back(b_zero);
      graph_zero[b_zero].push_back(a_zero);
      graph_one[a_one].push_back(b_one);
      graph_one[b_one].push_back(a_one);
    }
  }

  priority_queue<II, vector<II>, greater<II>> q;
  vector<I> distance(w * h, inf);
  q.emplace(0, at(0, 0));
  distance[at(0, 0)] = 0;
  while (!q.empty()) {
    I e = q.top().second;
    q.pop();

    for (I i : graph_zero[e]) {
      if (distance[e] < distance[i]) {
        distance[i] = distance[e];
        q.emplace(distance[i], i);
      }
    }
    for (I i : graph_one[e]) {
      if (distance[e] + 1 < distance[i]) {
        distance[i] = distance[e] + 1;
        q.emplace(distance[i], i);
      }
    }
  }

  if (distance[at(w - 1, h - 1)] < inf)
    cout << distance[at(w - 1, h - 1)] << '\n';
  else
    cout << "NIE" << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}
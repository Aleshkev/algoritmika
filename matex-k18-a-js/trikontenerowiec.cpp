#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
const I inf = 1e6;

struct heap {
  vector<I> data = {inf};

  void add(I x) {
    I i = data.size();
    data.push_back(x);
    while (i > 0 && data[i / 2] < data[i]) {
      swap(data[i / 2], data[i]);
      i /= 2;
    }
  }
  I top() { return data[1]; }
  void pop() {
    I last = data.size() - 1;
    data[1] = data[last];
    data.pop_back();
    I i = 1;
    for (;;) {
      I b = -1;
      for (I k = 0; k < 2; ++k) {
        if (2 * i + k < data.size() && data[i] < data[2 * i + k] &&
            (b == -1 || data[2 * i + k] > data[2 * i + b]))
          b = k;
      }
      if (b == -1) break;
      swap(data[i], data[2 * i + b]);
      i = 2 * i + b;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I m, n;
  cin >> m >> n;

  vector<vector<I>> add_at(m + 1);
  for (I i = 0; i < n; ++i) {
    I v, h;
    cin >> v >> h;
    if (h > m) continue;
    add_at[h].push_back(v);
  }

  I c = 0;
  heap q;
  for (I i = 1; i <= m; ++i) {
    for (I j : add_at[i]) {
      q.add(j);
    }
    if (q.data.size() > 1) {
      c += q.top();
      q.pop();
    }
  }
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

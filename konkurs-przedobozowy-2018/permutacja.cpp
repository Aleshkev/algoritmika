#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

template <typename T>
struct min_tree {
  I w;
  vector<T> data;
  T neutral;
  min_tree(I n, T neutral) : neutral(neutral) {
    for (w = 1; w < n;) w *= 2;
    data.resize(2 * w);
    fill(data.begin(), data.end(), neutral);
  }

  void set(I i, T x) {
    i = w + i;
    data[i] = x;
    for (i /= 2; i > 0; i /= 2) {
      data[i] = min(data[2 * i], data[2 * i + 1]);
    }
  }

  T get(I qb, I qe, I i, I rb, I re) {
    if (qb <= rb && re <= qe) {
      return data[i];
    }
    if (qe < rb || qb > re) {
      return neutral;
    }
    I mid = (rb + re) / 2;
    T a = get(qb, qe, 2 * i, rb, mid);
    T b = get(qb, qe, 2 * i + 1, mid + 1, re);
    return min(a, b);
  }
  T get(I a, I b) { return get(a, b, 1, 0, w - 1); }
};

I n;
vector<I> t;

vector<II> pairs;
vector<vector<I>> children;

void recurse(I b, I e, I parent, min_tree<II> &even, min_tree<II> &odd) {
  if (e - b < 0) return;

  I x_i = even.get(b, e).second;
  even.set(x_i, {inf, -1});

  I y_i = odd.get(x_i + 1, e).second;
  odd.set(y_i, {inf, -1});

  I current = pairs.size();
  pairs.push_back({t[x_i], t[y_i]});
  children.emplace_back();
  children[parent].push_back(current);

  recurse(b, x_i - 1, current, even, odd);
  recurse(x_i + 1, y_i - 1, current, odd, even);
  recurse(y_i + 1, e, current, even, odd);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  t.resize(n);
  for (I i = 0; i < n; ++i) cin >> t[i];

  min_tree<II> even(n, {inf, -1}), odd(n, {inf, -1});
  for (I i = 0; i < n; ++i) {
    (i % 2 == 0 ? even : odd).set(i, {t[i], i});
  }

  pairs.push_back({-1, -1});
  children.emplace_back();
  recurse(0, n - 1, 0, even, odd);

  priority_queue<pair<II, I>, vector<pair<II, I>>, greater<pair<II, I>>> q;
  q.push({{-1, -1}, 0});
  while (!q.empty()) {
    I top = q.top().second;
    q.pop();

    if (top > 0) cout << pairs[top].first << ' ' << pairs[top].second << ' ';

    for (I i : children[top]) {
      q.push({pairs[i], i});
    }
  }
  cout << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

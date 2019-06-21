#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

struct Max {
  I neutral = 0;
  I operator()(I a, I b) { return b > a ? b : a; }
};

template <typename T, class Combine>
struct point_tree {
  Combine combine;
  I n, w;
  vector<I> v;
  point_tree(I n_) : n(n_), w(1 << __lg(2 * n - 1)) {
    v.assign(2 * w, combine.neutral);
  }
  point_tree(const vector<T> &initial) : point_tree(initial.size()) {
    for (I i = 0; i < n; ++i) v[w + i] = initial[i];
    for (I i = w - 1; i > 0; --i) v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  void set(I i, T x) {
    for (i += w, v[i] = x, i /= 2; i > 0; i /= 2)
      v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  T get(I i) { return v[w + i]; }
  T get(I i, I j) {
    if (i == j) return get(i);
    i += w, j += w;
    T c = combine(v[i], v[j]);
    for (; i / 2 != j / 2; i /= 2, j /= 2) {
      if (i % 2 == 0) c = combine(c, v[i + 1]);
      if (j % 2 == 1) c = combine(c, v[j - 1]);
    }
    return c;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  vector<I> pref(n);
  partial_sum(v.begin(), v.end(), pref.begin());

  point_tree<I, Max> tree(v);

  while (m--) {
    I i, j;
    cin >> i >> j;
    --i, --j;
    I a = tree.get(i, j);
    I s = pref[j] - (i > 0 ? pref[i - 1] : 0);
    cout << (j - i + 1 >= 3 && s - a > a ? "TAK" : "NIE") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

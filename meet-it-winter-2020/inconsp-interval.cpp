#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef long double F;
I inf = 1e18;

struct Add {
  I neutral = 0;
  I operator()(I a, I b) { return a + b; }
};

struct Max {
  I neutral = -inf;
  I operator()(I a, I b) { return max(a, b); }
};
struct Min {
  I neutral = inf;
  I operator()(I a, I b) { return min(a, b); }
};

template <typename T, class Combine>
struct point_tree {
  Combine combine;
  I n, w;
  vector<I> v;
  point_tree(I n) : n(n), w(1 << __lg(2 * n - 1)) {
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
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  vector<I> prefix(n), suffix(n);
  partial_sum(v.begin(), v.end(), prefix.begin());
  reverse(v.begin(), v.end());
  partial_sum(v.begin(), v.end(), suffix.begin());
  reverse(v.begin(), v.end()), reverse(suffix.begin(), suffix.end());

  point_tree<I, Max> suffix_max(suffix), prefix_max(prefix);
  point_tree<I, Min> suffix_min(suffix), prefix_min(prefix);

  vector<I> left_hill(n), right_hill(n);
  for (I i = 0; i < n; ++i) {
    I j = i - 1;
    while (j >= 0 && v[j] <= v[i]) j = left_hill[j];
    left_hill[i] = j;
  }
  for (I i = n - 1; i >= 0; --i) {
    I j = i + 1;
    while (j < n && v[j] <= v[i]) j = right_hill[j];
    right_hill[i] = j;
  }

  F best_m = 1.0;
  I best_sum = 1, best_max = 1;
  for (I i = 0; i < n; ++i) {
    if (v[i] > 0) {
      I a = left_hill[i] + 1, b = right_hill[i] - 1;
      I max_left = suffix_max.get(a, i) - suffix[i];
      I max_right = prefix_max.get(i, b) - prefix[i];
      I sum = max_left + max_right + v[i];

      I x = sum, y = v[i];
      I g = __gcd(x, y);
      x /= g, y /= g;
      F m = (F)x / y;
      if (m > best_m) best_m = m, best_sum = x, best_max = y;
    } else {
      I a = left_hill[i] + 1, b = right_hill[i] - 1;
      I max_left = suffix_min.get(a, i) - suffix[i];
      I max_right = prefix_min.get(i, b) - prefix[i];
      I sum = max_left + max_right + v[i];

      I x = abs(sum), y = abs(v[i]);
      I g = __gcd(x, y);
      x /= g, y /= g;
      F m = (F)x / y;
      if (m > best_m) best_m = m, best_sum = x, best_max = y;
    }
  }

  cout << best_sum << "/" << best_max << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

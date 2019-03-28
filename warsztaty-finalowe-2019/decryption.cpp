#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

struct Tree {
  I w;
  vector<I> data;
  function<I(I, I)> f;
  Tree(vector<I> &v, function<I(I, I)> f) : f(f) {
    I n = v.size();
    for (w = 1; w < n;) w *= 2;
    data.resize(2 * w);

    copy(v.begin(), v.end(), data.begin() + w);
    for (I i = w - 1; i > 0; --i) {
      data[i] = f(data[2 * i], data[2 * i + 1]);
    }
  }
  I query(I a, I b) {
    I va = w + a, vb = w + b;
    I c = f(data[va], data[vb]);
    while (va / 2 != vb / 2) {
      if (va % 2 == 0) c = f(c, data[va + 1]);
      if (vb % 2 == 1) c = f(c, data[vb - 1]);
      va /= 2, vb /= 2;
    }
    return c;
  }
};

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  Tree min_tree(v, [](I a, I b) { return a < b ? a : b; });
  Tree max_tree(v, [](I a, I b) { return a > b ? a : b; });

  I c = 0;
  for (I i = 0; i < n;) {
    I j = f_lower_bound(i, n, [&](I j) {
      return min_tree.query(i, j) == v[i];
      ;
    });
    --j;

    I max_ij = max_tree.query(i, j);
    I k = f_lower_bound(i, j + 1, [&](I k) {
      return max_tree.query(k, j) == max_ij;
      ;
    });
    --k;

    i = k + 1;
    ++c;
  }
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

struct xyz {
  I x, y, z, i;
};
bool operator<(const xyz &l, const xyz &r) {
  return tie(l.x, l.y, l.z) < tie(r.x, r.y, r.z);
}

struct tree {
  I w;
  vector<I> data;
  tree(I n) {
    for (w = 1; w < n; w <<= 1)
      ;
    data.assign(2 * w, inf);
  }

  void set(I i, I x) {
    I v = w + i;
    data[v] = min(data[v], x);
    for (v /= 2; v > 1; v /= 2) data[v] = min(data[2 * v], data[2 * v + 1]);
  }
  I get(I a, I b) {
    I va = w + a, vb = w + b;
    I c = min(data[va], data[vb]);
    while (va / 2 != vb / 2) {
      if (va % 2 == 0) c = min(c, data[va + 1]);
      if (vb % 2 == 1) c = min(c, data[vb - 1]);
      va /= 2, vb /= 2;
    }
    return c;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<xyz> v(n);
  for (I i = 0; i < n; ++i) {
    cin >> v[i].x >> v[i].y >> v[i].z;
    v[i].i = i;
  }

  vector<I> ys;
  for (xyz &i : v) {
    ys.push_back(i.y);
  }
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (xyz &i : v) {
    i.y = lower_bound(ys.begin(), ys.end(), i.y) - ys.begin();
  }

  sort(v.begin(), v.end());

  vector<I> ans;

  tree min_x(ys.size());
  for (I i = 0; i < n;) {
    I k = 0;
    for (I j = i; j < n && v[i].x == v[j].x; ++j) ++k;

    for (I j = i; j < i + k; ++j) {
      if (v[j].y == 0 || min_x.get(0, v[j].y - 1) >= v[j].z) {
        ans.push_back(v[j].i);
      }
    }
    for (I j = i; j < i + k; ++j) {
      min_x.set(v[j].y, v[j].z);
    }

    i += k;
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (I i : ans) cout << i + 1 << ' ';
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

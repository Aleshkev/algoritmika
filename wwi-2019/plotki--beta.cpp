#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef pair<I, I> II;

I lsb(I x) { return x & -x; }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<II, null_type, less<II>, rb_tree_tag,
             tree_order_statistics_node_update>
    smartset;
struct quad {
  vector<smartset> v;
  I n;
  quad(I n) : n(n + 1) { v.resize(n + 1); }
  void insert(I x, I y) {
    ++x, ++y;
    for (I i = x; i < n; i += lsb(i)) v[i].insert({y, x});
  }
  I get(I x, I y) {
    ++x, ++y;
    I c = 0;
    for (I i = x; i > 0; i -= lsb(i)) c += v[i].order_of_key({y + 1, 0});
    return c;
  }
};

struct xyz {
  I x, y, z;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<xyz> v(n);
  for (I i = 0; i < 3 * n; ++i) {
    I j;
    cin >> j;
    (i < n ? v[j].x : (i < 2 * n ? v[j].y : v[j].z)) = i % n;
  }
  sort(v.begin(), v.end(),
       [&](const xyz &l, const xyz &r) { return l.z < r.z; });

  I c = 0;
  quad q(n);
  for (I i = 0; i < n; ++i) {
    c += q.get(v[i].x, v[i].y);
    q.insert(v[i].x, v[i].y);
  }
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

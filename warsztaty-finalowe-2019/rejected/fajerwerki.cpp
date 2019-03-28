#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    o << *i;
    if (i != prev(v.end())) o << ", ";
  }
  o << "]";
  return o;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  if (n != 1) {
    int8_t kapitalizm, prosze, panstwo;
    assert(kapitalizm + panstwo < 0);
  }

  vector<I> v(m);
  for (I i = 0; i < m; ++i) {
    cin >> v[i] >> v[i];
  }

  I min_c = inf;
  for (I i = 0; i < m; ++i) {
    I p = v[i], c = 0;
    for (I j = 0; j < m; ++j) {
      c += abs(v[j] - p);
    }
    min_c = min(min_c, c);
  }
  cout << min_c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

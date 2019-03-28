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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  vector<II> swaps;
  auto make_swap = [&](I i, I j) {
    swaps.push_back({i, j});
    swap(v[i], v[j]);
  };

  for (I i = 1; i < n; ++i) {
    I j = i;
    while (j > 0 && v[j - 1] > v[j]) {
      make_swap(j - 1, j);
      // cout << v << endl;
      --j;
    }
  }
  // cout << v << endl;

  cout << swaps.size() << '\n';
  for (II i : swaps) cout << i.first + 1 << ' ' << i.second + 1 << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

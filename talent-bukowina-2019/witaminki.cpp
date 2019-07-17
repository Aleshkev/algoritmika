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
template <typename T, typename U>
ostream &operator<<(ostream &o, const pair<T, U> &v) {
  o << "(" << v.first << ", " << v.second << ")";
  return o;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  I zeroes = 0, ones = 0;
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    if (x % 2 == 0)
      ++zeroes;
    else
      ++ones;
  }

  const I mod = 1e6 + 3;
  I c = 1;
  for (I i = 0; i < zeroes; ++i) c = 2 * c % mod;
  for (I i = 0; i < ones - 1; ++i) c = 2 * c % mod;
  c = (c + mod - 1) % mod;

  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

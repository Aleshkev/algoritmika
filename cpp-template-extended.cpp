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

  I n;

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

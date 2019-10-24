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
    if (i != v.begin()) o << ", ";
    o << *i;
  }
  return o << "]";
}
template <typename T, typename U>
ostream &operator<<(ostream &o, const map<T, U> &v) {
  o << "{";
  for (auto i = v.begin(); i != v.end(); ++i) {
    if (i != v.begin()) o << ", ";
    o << i->first << ": " << i->second;
  }
  return o << "}";
}
template <typename T, typename U>
ostream &operator<<(ostream &o, pair<T, U> p) {
  return o << "(" << p.first << ", " << p.second << ")";
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

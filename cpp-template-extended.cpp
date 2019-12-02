#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

#define debug_printable(template_thingies, type, start, printer, stop) \
  template <template_thingies>                                         \
  ostream &operator<<(ostream &o, const type &v) {                     \
    for (auto i = (o << start, v.begin()); i != v.end(); ++i)          \
      (i != v.begin() && (o << ", ")), o << printer;                   \
    return o << stop;                                                  \
  }
#define comma ,
debug_printable(typename T, vector<T>, "[", *i, "]");
debug_printable(typename T comma size_t N, array<T comma N>, "<", *i, ">");
debug_printable(typename T, set<T>, "{", *i, "}");
debug_printable(typename T comma typename U, map<T comma U>, "{",
                i->first << ": " << i->second, "}");
template <typename T, typename U>
ostream &operator<<(ostream &o, pair<T, U> p) {
  return o << "(" << p.first << ", " << p.second << ")";
}

int main() {
  // ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n;

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

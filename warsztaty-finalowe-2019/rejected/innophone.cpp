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

  vector<I> a(n), b(n);
  for (I i = 0; i < n; ++i) cin >> a[i] >> b[i];

  I max_c = 0;
  if (n <= 3000) {
    for (I p : a) {
      I c = 0;
      map<I, I> q;
      for (I i = 0; i < n; ++i) {
        if (p <= a[i]) {
          c += p;
        } else {
          ++q[0];
          --q[b[i]];
        }
      }
      I z = 0;
      if (!q.empty()) {
        I x = 0;
        for (II i : q) {
          z = max(z, x * i.first);
          x += i.second;
        }
      }
      c += z;

      // cout << p << ": " << c - z << ' ' << z << " -> " << c << '\n';
      max_c = max(max_c, c);
    }
  } else {
    map<I, I> q;
    for (I i = 0; i < n; ++i) {
      ++q[0];
      --q[a[i]];
    }
    I z = 0;
    I x = 0;
    for (II i : q) {
      z = max(z, x * i.first);
      x += i.second;
    }
    max_c = z;
  }
  cout << max_c << '\n';


#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    cout << *i;
    if (i != prev(v.end())) cout << ", ";
  }
  cout << "]";
  return o;
}

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

// Test the functions.
int main() {
  vector<I> v = {1, 1, 2, 2, 2, 3, 4, 10, 20, 1, 2, 3};
  set<I> w(v.begin(), v.end());
  cout << v << endl;

  // Should be equivalent.
  cout << f_lower_bound(0, v.size(), [&](I i) { return v[i] < 2; }) << endl;
  cout << lower_bound(v.begin(), v.end(), 2) - v.begin() << endl;

  system("pause");
  return 0;
}

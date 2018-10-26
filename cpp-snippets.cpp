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

// Test the functions.
int main() {
  vector<I> v = {1, 2, 3, 4, 10, 20, 1, 2, 3};
  set<I> w(v.begin(), v.end());

  cout << v << endl;
  system("pause");
  return 0;
}

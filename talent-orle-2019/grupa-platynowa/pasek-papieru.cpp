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

vector<bool> fold(vector<bool> v) {
  I n = v.size();
  if (n <= 1) return v;
  for (I i = 1; i < n; ++i) {
    bool ok = true;
    for (I j = 0; j < i; ++j) {
      if (i + j < n && v[i - j - 1] != v[i + j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      if (2 * i < n) {
        reverse(v.begin(), v.end());
        v.resize(n - i);
      } else {
        v.resize(i);
        reverse(v.begin(), v.end());
      }
      // cout << v << endl;
      return fold(v);
    }
  }
  return v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    vector<bool> v;
    for (char c : s) {
      v.push_back(c == '0' ? 0 : 1);
    }

    cout << fold(v).size() << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

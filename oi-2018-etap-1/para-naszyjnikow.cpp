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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I q;
  cin >> q;

  for (I qi = 0; qi < q; ++qi) {
    I n, m;
    cin >> n >> m;
    vector<bool> a(n + 1), b(m + 1);

    for (I i = 1; i <= n; ++i) {
      I x;
      cin >> x;
      a[i] = (x + a[i - 1]) % 2;
    }
    for (I i = 1; i <= m; ++i) {
      I x;
      cin >> x;
      b[i] = (x + b[i - 1]) % 2;
    }
    // cout << a << endl;
    // cout << b << endl;

    for (I l = min(n, m) + 1; l >= 0; --l) {
      bool ok = false;
      for (I k = 0; k < 2; ++k) {
        bool found_a = false, found_b = false;
        for (I i = 0; i + l <= n; ++i) {
          if ((a[i] + a[i + l]) % 2 == k) {
            found_a = true;
            break;
          }
        }
        for (I i = 0; i + l <= m; ++i) {
          if ((b[i] + b[i + l]) % 2 == k) {
            found_b = true;
            break;
          }
        }
        if (found_a && found_b) {
          ok = true;
          break;
        }
      }
      if (ok) {
        cout << l << '\n';
        break;
      }
    }
  }

#ifdef UNITEST
  // cout.flush();
  // system("pause");
#endif
  return 0;
}

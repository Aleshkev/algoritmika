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

  const I p = 1e9 + 7;

  srand(time(0));

  vector<I> a(n), b(n);
  vector<vector<I>> strip(n);
  for (I i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    // a[i] = rand() % 10;
    // b[i] = a[i] + rand() % 5;
    // cout << a[i] << ' ' << b[i] << endl;
    strip[i].assign(b[i] - a[i] + 1, 0);
  }

  // I correct_c = 0;
  // {
  //   vector<vector<I>> strip(n);
  //   for (I i = 0; i < n; ++i) {
  //     strip[i].assign(b[i] - a[i] + 1, 0);
  //   }
  //   fill(strip[n - 1].begin(), strip[n - 1].end(), 1);
  //   for (I i = n - 1 - 1; i >= 0; --i) {
  //     fill(strip[i].begin(), strip[i].end(), 1);

  //     for (I j = i + 1; j < n; ++j) {
  //       // if (b[j] < a[i] || a[j] > b[i]) continue;
  //       if (b[j] <= a[i]) continue;

  //       for (I k = 0; a[i] + k <= b[i]; ++k) {
  //         for (I z = max<I>(0, a[i] + k - a[j] + 1); a[j] + z <= b[j]; ++z) {
  //           // cout << vector<I>({i, j, k, z}) << endl;
  //           strip[i][k] += strip[j][z];
  //         }
  //       }
  //     }

  //     for (I k = 0; a[i] + k <= b[i]; ++k) {
  //       strip[i][k] %= p;
  //     }
  //   }
  //   // for (auto v : strip) {
  //   //   cout << v << endl;
  //   // }

  //   correct_c = 0;
  //   for (auto s : strip) {
  //     for (I i : s) {
  //       correct_c = (correct_c + i) % p;
  //     }
  //   }
  // }

  // cout << correct_c << '\n';

  strip[n - 1][strip[n - 1].size() - 1] = 1;
  for (I i = strip[n - 1].size() - 1 - 1; i >= 0; --i) {
    strip[n - 1][i] = strip[n - 1][i + 1] + 1;
  }

  for (I i = n - 1 - 1; i >= 0; --i) {
    for (I k = strip[i].size() - 1; k >= 0; --k) {
      if (k + 1 < strip[i].size()) strip[i][k] = strip[i][k + 1];
      ++strip[i][k];

      for (I j = i + 1; j < n; ++j) {
        if (a[i] + k - a[j] + 1 >= (I)strip[j].size()) continue;
        strip[i][k] += strip[j][max<I>(0, a[i] + k - a[j] + 1)];
        // strip[i][k] %= p;
      }

      strip[i][k] %= p;
    }

    // for (I j = i + 1; j < n; ++j) {
    //   if (b[j] <= a[i]) continue;

    //   for (I k = 0; a[i] + k <= b[i]; ++k) {
    //     for (I z = max<I>(0, a[i] + k - a[j] + 1); a[j] + z <= b[j]; ++z) {
    //       // cout << vector<I>({i, j, k, z}) << endl;
    //       strip[i][k] += strip[j][z];
    //     }
    //   }
    // }

    // for (I k = 0; a[i] + k <= b[i]; ++k) {
    //   strip[i][k] %= p;
    // }
  }
  // for (auto v : strip) {
  //   cout << v << endl;
  // }

  I c = 0;
  for (auto s : strip) {
    c = (c + s.front()) % p;
  }
  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
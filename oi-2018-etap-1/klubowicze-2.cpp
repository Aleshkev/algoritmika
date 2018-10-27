#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

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

I complete_search(I n, const vector<I> &v) {
  I m = v.size();
  vector<vector<I>> p(n, vector<I>(m));
  for (I i = 0; i < n; ++i) {
    for (I j = 0; j < m; ++j) {
      p[i][j] = (v[j] & (1 << i) ? 1 : 0);
    }
  }

  // cout << endl;
  // for (I k = 0; k < n; ++k) {
  //   for (I j = 0; j < m; ++j) {
  //     cout << p[k][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  I c = 0;

  for (I i = 0; i < m; ++i) {
    for (I j = i + 1; j < m; ++j) {
      // cout << i << ", " << j << ": ";
      bool ok = true;
      for (I k = 0; k < n; ++k) {
        bool zeros_inside = count(p[k].begin() + i, p[k].begin() + j, 0) > 0,
             ones_inside = count(p[k].begin() + i, p[k].begin() + j, 1) > 0;
        bool zeros_outside = (count(p[k].begin(), p[k].begin() + i, 0) +
                              count(p[k].begin() + j, p[k].end(), 0)) > 0,
             ones_outside = (count(p[k].begin(), p[k].begin() + i, 1) +
                             count(p[k].begin() + j, p[k].end(), 1)) > 0;
        // cout << I(zeros_inside) << " " << I(zeros_outside) << " ";
        // cout << I(ones_inside) << " " << I(ones_outside) << endl;
        if (zeros_inside ^ zeros_outside) ok = false;
        if (ones_inside ^ ones_outside) ok = false;
      }
      if (ok) {
        // cout << "solution: " << i << ", " << j << endl;
        ++c;
      }
    }
  }
  return c;
}

I empty_fields(map<I, I> increment) {
  I result = 0;
  I counter = 0;
  I last = increment.begin()->first;
  for (II p : increment) {
    if (counter == 0) {
      result += (p.first - last);
    }
    counter += p.second;
    last = p.first;
  }
  return result;
}

I linear(I m, const vector<I> &v) {
  I n = v.size();

  vector<vector<bool>> value(m, vector<bool>(n));
  for (I k = 0; k < m; ++k) {
    for (I i = 0; i < n; ++i) value[k][i] = (v[i] & (1 << k) ? 1 : 0);
    // cout << k << ": " << value[k] << endl;
  }

  vector<bool> ignore_k(m);
  for (I k = 0; k < m; ++k) {
    I c = count(value[k].begin(), value[k].end(), 1);
    if (c == 1 || c == n - 1) return 0;
    ignore_k[k] = (c == 0 || c == n);
  }

  vector<vector<I>> next_different(m, vector<I>(n));
  for (I k = 0; k < m; ++k) {
    if (ignore_k[k]) continue;

    next_different[k][n - 1] =
        find(value[k].begin(), value[k].end(), !value[k][n - 1]) -
        value[k].begin();
    for (I i = n - 1 - 1; i >= 0; --i) {
      if (value[k][i] != value[k][i + 1]) {
        next_different[k][i] = i + 1;
      } else {
        next_different[k][i] = next_different[k][i + 1];
      }
    }
  }

  vector<vector<I>> prev_different(m, vector<I>(n));
  for (I k = 0; k < m; ++k) {
    if (ignore_k[k]) continue;

    prev_different[k][0] =
        (n -
         (find(value[k].rbegin(), value[k].rend(), !value[k][0]) -
          value[k].rbegin()) -
         1);

    for (I i = 1; i < n; ++i) {
      if (value[k][i] != value[k][i - 1]) {
        prev_different[k][i] = i - 1;
      } else {
        prev_different[k][i] = prev_different[k][i - 1];
      }
    }
  }

  I c = 0;
  for (I i = 0; i < n; ++i) {  // O(nk lg k).
    // cout << "i = " << i << ": " << endl;
    map<I, I> increment;
    for (I k = 0; k < m; ++k) {
      if (ignore_k[k]) continue;

      I a = prev_different[k][(n + i - 1) % n];
      I b = next_different[k][i];

      if (a < i && i < b) {
        ++increment[i + 1];
        --increment[b + 1];
      } else if (i < b && b < a) {
        ++increment[i + 1];
        --increment[b + 1];
        ++increment[a + 1];
      } else {
        ++increment[i + 1];
      }
    }

    increment[n];
    c += empty_fields(increment);  // O(k lg k).
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> v(m);
  for (I &i : v) cin >> i;

  cout << linear(n, v) << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

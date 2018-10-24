#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> v(m);
  for (I &i : v) cin >> i;

  cout << complete_search(n, v) << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

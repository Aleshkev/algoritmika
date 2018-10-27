#include <bits/stdc++.h>

using namespace std;

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

int64_t linear(const vector<vector<bool>> &value) {
  int32_t m = value.size(), n = value[0].size();

  vector<bool> ignore_k(m, false);
  for (int32_t k = 0; k < m; ++k) {
    int32_t c = count(value[k].begin(), value[k].end(), 0);
    if (c == 1 || n - c == 1) return 0;
    if (c == 0 || n - c == 0) ignore_k[k] = true;
  }

  vector<int32_t> prev_different(n);
  for (int32_t k = 0; k < m; ++k) {
    if (ignore_k[k]) continue;

    int32_t current = find(value[k].rbegin(), value[k].rend(), !value[k][0]) -
                      value[k].rbegin() + 1;
    prev_different[0] = max(prev_different[0], current);
    for (int32_t i = 1; i < n; ++i) {
      if (value[k][i] == value[k][i - 1]) {
        current += 1;
      } else {
        current = 1;
      }
      prev_different[i] = max(prev_different[i], current);
    }
  }

  vector<int32_t> next_different(n);
  for (int32_t k = 0; k < m; ++k) {
    if (ignore_k[k]) continue;

    int32_t current = find(value[k].begin(), value[k].end(), !value[k][n - 1]) -
                      value[k].begin() + 1;
    next_different[n - 1] = max(next_different[n - 1], current);
    for (int32_t i = n - 2; i >= 0; --i) {
      if (value[k][i] == value[k][i + 1]) {
        current += 1;
      } else {
        current = 1;
      }
      next_different[i] = max(next_different[i], current);
    }
  }

  int64_t result = 0;
  for (int32_t i = 0; i < n; ++i) {
    result += max(int32_t(0), n - (prev_different[(n + i - 1) % n] + 1 +
                                   next_different[i] + 1 - 1));
  }

  // cout << prev_different << endl;
  // cout << next_different << endl;

  return result / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int32_t m, n;
  cin >> m >> n;

  vector<vector<bool>> value(m, vector<bool>(n));
  for (int32_t i = 0; i < n; ++i) {
    int32_t x;
    cin >> x;
    for (int32_t k = 0; k < m; ++k) value[k][i] = (x & (1 << k));
  }

  cout << linear(value) << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

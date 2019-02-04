#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

vector<I> compute_r(const string &z) {
  string s = z;
  I n = s.size();
  s.insert(s.begin(), '#');
  s.push_back('$');
  vector<I> r(n + 1);
  r[0] = 0;
  int i = 1;
  int t = 0;
  while (i <= n) {
    while (s[i - t] == s[i + t + 1]) t++;
    r[i] = t;
    int k = 1;
    while (k <= t && r[i - k] != r[i] - k) {
      r[i + k] = min(r[i - k], r[i] - k);
      k++;
    }
    t -= k;
    t = max(0, t);
    i += k;
  }
  return r;
}

I solve(string &s) {
  I n = s.size();

  vector<I> d = compute_r(s);

  I m = 0;
  for (I i = 0; i < n - 2 * m; ++i) {
    for (I x = m + 1; i + x < n && x <= d[i] / 2; ++x) {
      if (d[i + x] >= x) {
        m = max(m, x);
      }
    }
  }

  return m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;

    cout << 4 * solve(s) << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

// Ten kod jest stosunkowo długi, ale za to bardzo prosty, debugowanie zajęło
// nie więcej niż pół godziny.

string try_constructing(const string &a, const string &b,  //
                        I unequal, char c, I k) {
  I n = (a.size() + b.size()) / 2;
  I original_k = k;

  string r(n, '-');

  for (I i = 0; i < unequal; ++i) {
    r[i] = b[i];
    if (a[i] != b[i]) --k;
  }

  r[unequal] = c;
  if (a[unequal] != c) --k;

  for (I i = unequal + 1; i < n; ++i) {
    if (k > 0 && a[i] != '9')
      r[i] = '9', --k;
    else if (k == n - i && a[i] == '9')
      r[i] = '8', --k;
    else
      r[i] = a[i];
  }

  I different = 0;
  for (I i = 0; i < n; ++i) different += (a[i] != r[i]);
  if (different != original_k || r >= b) return "-1";

  return r;
}

string solve(const string &a, const string &b, I k) {
  I n = (a.size() + b.size()) / 2;
  I original_k = k;

  vector<I> d(n);
  d[0] = (a[0] != b[0]);
  for (I i = 1; i < n; ++i) d[i] = d[i - 1] + (a[i] != b[i]);

  for (I i = n - 1; i >= 0; --i) {
    if (b[i] == '0') continue;

    I k = original_k - (i > 0 ? d[i - 1] : 0);
    if (k < 0) continue;

    vector<char> options;
    if (a[i] < b[i] && k <= n - i - 1)  //
      options.push_back(a[i]);
    if (1 <= k && k <= n - i)
      if (a[i] != b[i] - 1)
        options.push_back(b[i] - 1);
      else if (a[i] == b[i] - 1 && b[i] != '1')
        options.push_back(b[i] - 2);
    if (options.empty()) continue;

    vector<string> r;
    for (char c : options)
      r.push_back(try_constructing(a, b, i, c, original_k));
    return *max_element(r.begin(), r.end());
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I q;
  cin >> q;
  while (q--) {
    string a, b;
    I k;
    cin >> a >> b >> k;

    auto r = solve(a, b, k);
    cout << (r < b ? r : "-1") << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

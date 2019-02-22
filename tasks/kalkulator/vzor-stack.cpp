#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string s;
  getline(cin, s);
  s = "(" + s + ")";
  I n = s.size();

  const I mod = 1e9 + 7;

  I ans = 0;
  vector<I> v;
  for (I i = 0; i < n; ++i) {
    if (s[i] == ' ' || s[i] == '#') continue;
    if (s[i] == '(') {
      v.push_back(0);
    } else if (s[i] == ')') {
      I x = v.back();
      v.pop_back();
      if (v.empty()) {
        ans = x;
        break;
      }
      v.back() = (2 * v.back() + x) % mod;
    } else {
      I x = 0;
      while (isdigit(s[i])) {
        x = (10 * x + s[i] - '0') % mod;
        ++i;
      }
      --i;
      v.back() = (2 * v.back() + x) % mod;
    }
  }

  cout << ans << '\n';

  return 0;
}

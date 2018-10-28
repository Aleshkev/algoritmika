#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  I n = s.size();

  vector<bool> v(n);

  for (I i = 1; i < n; ++i) {
    if (s[i] == 'a') {
      v[i] = true;
      v[i - 1] = !v[i - 1];
    }
  }

  for (bool i : v) cout << i << ' ';
  cout << '\n';

  return 0;
}

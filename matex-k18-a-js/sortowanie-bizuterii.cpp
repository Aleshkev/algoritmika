#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  I n;
  cin >> n;

  vector<string> s(n);
  for (string &i : s) cin >> i;

  sort(s.begin(), s.end(), [](const string &l, const string &r) {
    return (l.size() != r.size() ? l.size() < r.size() : l < r);
  });

  for (string &i : s) cout << i << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

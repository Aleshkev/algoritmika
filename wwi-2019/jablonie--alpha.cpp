#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;
  vector<I> v(n);
  for (I &i : v) cin >> i;
  sort(v.begin(), v.end());

  while (m--) {
    string s;
    cin >> s;
    if (s[0] == 'p') {
      I x;
      cin >> x;

      for (I i = 0; i < x; ++i) ++v[i];
      if (v[x - 1] > v[x]) {
        I y = lower_bound(v.begin(), v.begin() + x, v[x - 1]) - v.begin();
        I z = upper_bound(v.begin() + x, v.end(), v[x]) - v.begin();
        sort(v.begin() + y, v.begin() + z);
      }
    } else {
      I a, b;
      cin >> a >> b;
      cout << upper_bound(v.begin(), v.end(), b) -
                  lower_bound(v.begin(), v.end(), a)
           << "\n";
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

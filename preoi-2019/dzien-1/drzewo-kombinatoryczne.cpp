#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;
  sort(v.begin(), v.end());

  I q;
  cin >> q;
  while (q--) {
    I x;
    cin >> x;
    cout << upper_bound(v.begin(), v.end(), x) -
                lower_bound(v.begin(), v.end(), x)
         << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

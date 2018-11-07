#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  I s = accumulate(v.begin(), v.end(), 0);

  I k = *max_element(v.begin(), v.end());
  for (; n * k - s <= s;) ++k;
  cout << k << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

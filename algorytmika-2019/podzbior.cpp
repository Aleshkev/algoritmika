#include <bits/stdc++.h>
using namespace std;
typedef uintmax_t I;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, q;
  cin >> n >> q;

  vector<I> v;
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;

    for (I y : v) x = min(x, x ^ y);
    if (x != 0) v.push_back(x);
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  for (I i = 0; i < q; ++i) {
    I x;
    cin >> x;

    for (I y : v) x = min(x, x ^ y);
    cout << (x == 0 ? "TAK" : "NIE") << "\n";
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

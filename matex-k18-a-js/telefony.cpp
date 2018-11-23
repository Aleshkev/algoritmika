#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  vector<II> v(n);
  for (II &i : v) {
    I x;
    cin >> x;
    i.first = ((x % 10000 / 1000) * 1000 + (x % 10 / 1) * 100 +
               (x % 100 / 10) * 10 + (x % 1000 / 100) * 1);
    i.second = x;
  }

  sort(v.begin(), v.end());

  for (II i : v) cout << i.second << ' ';
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  for (I k = 0; k < 2; ++k)
    for (I i = 0; i < n + k; ++i)
      cout << string(n - i, ' ') << string(2 * i + 1, '*') << '\n';
  for (I k = 0; k < 2; ++k) cout << string(n, ' ') << '*' << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> r(n);
  for (I i = 0; i < n; ++i) {
    cin >> r[i];
    if (i > 0 && r[i] > r[i - 1]) r[i] = r[i - 1];
  }

  I l = n - 1;
  for (I i = 0; i < m; ++i) {
    I a;
    cin >> a;

    while (l >= 0 && r[l] < a) --l;
    --l;
  }
  cout << max((I)0, l + 1 + 1) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

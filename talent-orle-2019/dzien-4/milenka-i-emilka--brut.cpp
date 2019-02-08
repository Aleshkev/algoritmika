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

  I x = 0;
  for (I i = 0; i + 1 < n; ++i) {
    vector<bool> taken(n + 1);
    I gaps = 1;
    auto add = [&](I i) {
      if (i > 0 && taken[i - 1] && taken[i + 1]) {
        --gaps;
      } else if (i > 0 && !taken[i - 1] && !taken[i + 1]) {
        ++gaps;
      }
      taken[i] = true;
    };
    add(v[i]);
    add(v[i + 1]);
    if (gaps <= 3) ++x;
    for (I j = i + 2; j < n; ++j) {
      add(v[j]);
      if (gaps <= 3) ++x;
    }
  }
  cout << x << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

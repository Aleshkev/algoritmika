#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  I c = 0;

  for (I i = 0; i < n; ++i) {
    I x, y;
    cin >> x >> y;
    c = max(c, x + y);
  }

  cout << c << '\n';

  return 0;
}

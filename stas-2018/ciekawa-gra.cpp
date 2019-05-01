#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, a, b;
  cin >> n >> a >> b;
  I smaller = min(a, b), bigger = max(a, b);
  I only_bigger = 0, by_both = 0, to_catch = 0;
  for (I i = 0; i < n; ++i) {
    I x;
    cin >> x;
    x %= (a + b);
    if (x >= bigger)
      ++by_both;
    else if (x >= smaller)
      ++only_bigger;
    if (x - smaller >= smaller && a != b) ++to_catch;
  }

  if (only_bigger > 0 ||
      ((a == smaller && to_catch > 0) || (b == smaller && to_catch > 1))) {
    cout << (a == smaller ? "Jas" : "Malgosia") << '\n';
  } else {
    cout << (by_both % 2 != 0 ? "Jas" : "Malgosia") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
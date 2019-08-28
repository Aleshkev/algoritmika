#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> factorials = {1};
  while (factorials.back() < 1e9) {
    factorials.push_back(factorials.back() * (factorials.size() + 1));
  }

  static vector<I> memo = {0};

  function<I(I)> r = [&](I x) {
    if (x < memo.size())
      return memo[x];
    else
      memo.push_back(x);

    I c = x;
    for (I f : factorials) {
      if (x - f < 0) break;
      c = min(c, memo[x - f] + 1);
    }

    memo[x] = c;
    return c;
  };

  for (I i = 1;; ++i) {
    if (i > 1e18 || r(i) > n) {
      cout << i << "\n";
      break;
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

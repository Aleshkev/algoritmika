#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;

struct R {
  I x, y, z;
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I a, b, c;
  cin >> a >> b >> c;

  I r = __gcd(a, __gcd(b, c));

  R v = {-inf, -inf, -inf};
  constexpr I lim = 5000;
  for (I x = -lim; x <= lim; ++x) {
    for (I y = -lim; y <= lim; ++y) {
      I z = (r - a * x - b * y) / c;
      if (a * x + b * y + c * z == r) {
        v = {x, y, z};
        break;
      }
    }
    if (v.x != -inf) break;
  }

  if (v.x == -inf) {
    cout << "NIE\n";
  } else {
    cout << v.x << " " << v.y << " " << v.z << "\n";
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  F p, s, v;
  I n;
  cin >> p >> s >> v >> n;

  F h = v / p;
  for (I i = 0; i < n; ++i) {
    F l, d;
    cin >> l >> d;

    h += pow(l, 3) * d / (p - pow(l, 2));
  }
  cout << fixed << setprecision(4) << I(h * 1e4) / F(1e4) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

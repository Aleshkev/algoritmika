#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;
  for (I i = 0; i < q; ++i) {
    I x, y, z;
    cin >> x >> y >> z;
    cout << "Case " << i + 1 << ": "
         << (x ^ y ^ z ^ min({x, y, z}) ^ max({x, y, z})) << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
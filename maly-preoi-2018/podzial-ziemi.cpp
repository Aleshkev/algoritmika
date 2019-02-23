#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  I c = []() {
    I n;
    cin >> n;

    vector<I> v(n);
    for (I &i : v) cin >> i;
    I sum_a = accumulate(v.begin(), v.end(), 0);

    if (sum_a % 2 != 0) return inf;

    I need = sum_a / 2;

    vector<I> c2(need + 1, inf), c0(need + 1, inf), c_new(need + 1);
    c0[v[0]] = 0;
    for (I i = 1; i < n; ++i) {
      fill(c_new.begin(), c_new.end(), inf);
      for (I k = 1; v[i] + k <= need; ++k) {
        c_new[v[i] + k] = min(c2[k] + 2, c0[k]);
      }
      c_new[v[i]] = min(c_new[v[i]], (I)1);

      // Swap.
      for (I k = 1; k <= need; ++k) {
        c2[k] = min(c2[k], c0[k]);
      }
      c0 = c_new;
    }

    if (c0[need] < inf) return c0[need];
    return inf;
  }();

  if (c < inf)
    cout << c << '\n';
  else
    cout << "WOJNA" << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
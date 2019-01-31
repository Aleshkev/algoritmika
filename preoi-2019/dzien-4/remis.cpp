#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

struct modded {
  I p, lim;
  vector<I> power;
  I sum_powers;
  modded(I m, I p, I lim) : p(p), lim(lim) {
    power.resize(m - 2 + 1);
    power[0] = 1;
    for (I i = 1; i <= m - 2; ++i) power[i] = power[i - 1] * p % lim;
    sum_powers = 0;
    for (I i : power) sum_powers += i;
  }

  I extend(I prev, I x) {
    if (x == 1) {
      return (prev + sum_powers) % lim;
    } else {
      return (prev + lim - power[x - 2]) % lim;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  []() {
    I n, m;
    cin >> n >> m;

    if (m == 1) {
      cout << n * (n + 1) / 2 << '\n';
      return;
    }

    vector<I> v(n);
    for (I i = 0; i < n; ++i) cin >> v[i];

    modded one(m, 1061129, 3367900313), two(m, 1061141, 5463458053);

    vector<II> z(n + 1);
    z[0] = {0, 0};
    for (I i = 0; i < n; ++i) {
      z[i + 1].first = one.extend(z[i].first, v[i]);
      z[i + 1].second = two.extend(z[i].second, v[i]);
    }

    I c = 0;
    map<II, I> o;
    for (II i : z) {
      c += o[i];
      ++o[i];
    }

    cout << c << '\n';
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

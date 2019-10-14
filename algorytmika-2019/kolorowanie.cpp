#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
typedef pair<I, I> II;

struct mat {
  I v[9];
  mat() { fill(v, v + 9, 0); }
  mat(function<I(I, I)> f) {
    for (I x = 0; x < 3; ++x)
      for (I y = 0; y < 3; ++y) at(x, y) = f(x, y);
  }
  I &at(I x, I y) { return v[y * 3 + x]; }
  const I &at(I x, I y) const { return v[y * 3 + x]; }
};
#define filled(EXPR) mat([&](I x, I y) { return EXPR; })

const I mod = 1e9 + 33;
mat operator*(const mat &a, const mat &b) {
  mat r;
  for (I x = 0; x < 3; ++x)
    for (I y = 0; y < 3; ++y)
      for (I i = 0; i < 3; ++i)
        r.at(x, y) = (r.at(x, y) + a.at(x, i) * b.at(i, y)) % mod;
  return r;
}

mat neutral = filled(x == y);

template <typename T>
T power(T n, I k) {
  if (k == 0) return neutral;
  if (k == 1) return n;
  if (k == 2) return n * n;
  auto half = power(n, k / 2);
  auto whole = half * half;
  if (k % 2 == 1) whole = whole * n;
  return whole;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<II> v(m);
  for (I i = 0; i < m; ++i) {
    char c;
    cin >> v[i].first >> c;
    --v[i].first, v[i].second = c - 'A';
  }
  sort(v.begin(), v.end());

  mat r;
  if (!v.empty() && v[0].first == 0)
    r = filled(x == 0 && y == v[0].second);
  else
    r = filled(x == 0);

  mat default_transform = filled(x != y);

  I handled_to = 0;
  for (II p : v) {
    if (p.first == 0) continue;
    r = r * power(default_transform, p.first - handled_to - 1);
    r = r * filled(x != y && y == p.second);
    handled_to = p.first;
  }
  r = r * power(default_transform, n - handled_to - 1);

  cout << (r.at(0, 0) + r.at(0, 1) + r.at(0, 2)) % mod << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

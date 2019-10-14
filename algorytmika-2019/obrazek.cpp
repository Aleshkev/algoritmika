#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

constexpr I N = 32;
struct mat {
  I v[N * N];
  mat() { fill(v, v + N * N, 0); };
  mat(function<I(I, I)> f) {
    for (I x = 0; x < N; ++x)
      for (I y = 0; y < N; ++y) at(x, y) = f(x, y);
  }
#define filled(EXPR) mat([&](I x, I y) { return EXPR; })

  I &at(I x, I y) { return v[y * N + x]; }
  const I &at(I x, I y) const { return v[y * N + x]; }
};

const I mod = 1e9 + 9;
mat operator*(const mat &a, const mat &b) {
  mat r;
  for (I x = 0; x < N; ++x)
    for (I y = 0; y < N; ++y)
      for (I i = 0; i < N; ++i)
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

  I w, h;
  cin >> w >> h;

  vector<bitset<5>> states;
  for (I m = 0; m < (1 << h); ++m) states.push_back(m);

  mat base = filled(x == 0);
  mat transform;
  for (I a_i = 0; a_i < states.size(); ++a_i) {
    for (I b_i = 0; b_i < states.size(); ++b_i) {
      auto &a = states[a_i], &b = states[b_i];
      bool ok = true;
      for (I i = 0; i + 1 < h; ++i)
        if (a[i] == a[i + 1] && a[i + 1] == b[i] && b[i] == b[i + 1])
          ok = false;
      transform.at(a_i, b_i) = ok;
    }
  }

  auto r = base * power(transform, w - 1);

  I c = 0;
  for (I i = 0; i < states.size(); ++i) {
    c = (c + r.at(0, i)) % mod;
  }
  cout << c << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

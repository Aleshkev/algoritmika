#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

// Panie Farbisiu, przez dwie godziny męczyłem się optymalizując ten kod. Byłem
// gotowy już napisać mnożenie macierzy algorytmem Strassena.
//
// Dwa razy pomyślałem sobie "w sumie to nie zawsze macierz musi być taka duża"
// i za każdym razem stwierdziłem, że przecież w najgorszym przypadku właśnie
// jest, a ja mam przekroczenia limitów czasu.
//
// Jak może już może się Pan domyślić, nie pomyślałem o tym, że w
// przeciwieństwie do każdego innego kontestu limity czasu nie są takie same na
// wszystkich testach. Dodatkowo nie rosną nawet liniowo razem z numerem testu.
//
// Jestem bardzo zawiedziony i za karę nie zrobię już Pociągów.

constexpr I N = 102;
I M;
struct mat {
  I v[N * N] = {0};
#define at(X, Y) v[N * (Y) + (X)]
};

const int64_t mod = 1e9 + 7;
#define lim(X) ((X) < mod ? (X) : (X) % mod)
mat operator*(const mat &a, const mat &b) {
  mat r;
  for (I x = 0; x < M; ++x)
    for (I y = 0; y < M; ++y) {
      int64_t c = 0;
      for (I i = 0; i < M; ++i) {
        auto z = (int64_t)a.at(x, i) * b.at(i, y);
        z = lim(z);
        c += z;
        c = lim(c);
      }
      r.at(x, y) = c;
    }
  return r;
}

template <typename T>
T power(const T &n, int64_t k) {
  if (k == 1) return n;
  if (k == 2) return n * n;
  auto half = move(power(n, k / 2));
  auto whole = half * half;
  if (k % 2 == 1) whole = whole * n;
  return whole;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int64_t n;
  I k;
  cin >> n >> k;
  M = k + 2;

  mat base;
  for (I y = 0; y <= k; ++y) base.at(0, y) = 1;

  mat trans;
  trans.at(0, 0) = 1;
  for (I y = 1; y <= k; ++y) {
    trans.at(0, y) = 1;
    for (I x = 1; x <= y; ++x) {
      trans.at(x, y) = lim(trans.at(x - 1, y - 1) + trans.at(x, y - 1));
    }
  }
  trans.at(k, k + 1) = trans.at(k + 1, k + 1) = 1;

  mat r = base * power(trans, n);

  cout << r.at(0, k + 1) << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

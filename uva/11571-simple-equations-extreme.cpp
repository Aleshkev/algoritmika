// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2618
//
// Also passes the simpler version:
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2612
//
// This code surely has some overflows *somewhere*, but I got AC, so who cares?

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
#define pI PRIiMAX

int main() {
  // Generate primes up to maximal possible bound.
  const I lim = cbrt(6e18) + 10;
  vector<bool> is_prime(lim + 1, true);
  for (I i = 2; i <= lim; ++i) {
    if (!is_prime[i]) {
      continue;
    }
    for (I j = i * i; j <= lim; j += i) {
      is_prime[j] = false;
    }
  }
  vector<I> primes;
  for (I i = 2; i <= lim; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  I q;
  scanf("%" pI, &q);

  for (I qi = 0; qi < q; ++qi) {
    I a, b, c;
    scanf("%" pI " %" pI " %" pI, &a, &b, &c);

    bool any_found = false;

    I bound = cbrt(b) + 1;

    // Prime-factorize b.
    I bx = b;
    vector<I> dividing_primes;
    for (I i : primes) {
      while (bx % i == 0) {
        dividing_primes.push_back(i);
        bx /= i;
      }
      if (bx == 1) break;
    }

    // Iterate through all divisors of b (powerset of prime factors of b).
    for (I m = 0; m < (1 << dividing_primes.size()); ++m) {
      I x = 1;
      for (I i = 0; i < dividing_primes.size(); ++i) {
        if (m & (1 << i)) {
          x *= dividing_primes[i];
        }
      }

      // Solve quadratic equation.
      I alpha = a - x;
      I beta = b / x;

      if (4 * beta > alpha * alpha) continue;
      I y = (alpha - sqrt(alpha * alpha - 4 * beta)) / 2;

      // Check if everything is OK.
      I z = a - x - y;
      if (x == y || y == z || x == z) continue;
      if (x + y + z != a) continue;
      if (x * y * z != b) continue;
      if (x * x + y * y + z * z != c) continue;

      // We half-implicitly assume x < y < z.
      vector<I> t = {x, y, z};
      sort(t.begin(), t.end());
      printf("%" pI " %" pI " %" pI "\n", t[0], t[1], t[2]);
      any_found = true;
      break;
    }

    if (!any_found) {
      printf("No solution.\n");
    }
  }

#ifdef __MINGW32__
  system("pause");
#endif
  return 0;
}

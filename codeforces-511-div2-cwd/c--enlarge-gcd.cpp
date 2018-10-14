#include <bits/stdc++.h>

using namespace std;

typedef int64_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // Create data needed for factorization.
  const I max_a = 15000000;
  vector<I> divisor(max_a + 1, 1);
  for (I i = 2; i * i <= max_a; ++i) {
    if (divisor[i] != 1) continue;

    divisor[i] = i;

    for (I j = i * i; j <= max_a; j += i) {
      if (divisor[j] == 1) divisor[j] = i;
    }
  }

  I n;
  cin >> n;

  vector<I> numbers(n);
  for (I i = 0; i < n; ++i) cin >> numbers[i];

  // Divide all numbers by GCD of all numbers.
  I numbers_gcd = __gcd(numbers[0], numbers[1]);
  for (I i = 2; i < n; ++i) numbers_gcd = __gcd(numbers_gcd, numbers[i]);
  for (I i = 0; i < n; ++i) numbers[i] /= numbers_gcd;

  // [prime] -> how many numbers are divisible by prime
  unordered_map<I, I> divisible_numbers;

  for (I number : numbers) {
    while (divisor[number] > 1) {
      I d = divisor[number];
      ++divisible_numbers[d];
      while (divisor[number] == d) {
        number /= d;
      }
    }
  }

  I c = n;
  for (auto p : divisible_numbers) {
    c = min(c, n - p.second);
  }

  if (c < n) {
    cout << c << '\n';
  } else {
    cout << "-1\n";
  }

  // #ifdef __MINGW32__
  //   cout.flush();
  //   system("pause");
  // #endif
  return 0;
}

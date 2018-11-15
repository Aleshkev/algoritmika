// Also known as Perfect Security from Codeforces.
// http://codeforces.com/contest/947/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

const I depth = 30;
const I w = (1 << depth);
unordered_map<I, I> population;

void add(I number, I x = +1) {
  I i = w + number;
  population[i] += x;
  for (i /= 2; i > 0; i /= 2)
    population[i] = population[2 * i] + population[2 * i + 1];
}
I decide(I number) {
  I i = 1;

  for (I k = depth - 1; k >= 0; --k) {
    I b = ((number & (1 << k)) > 0);
    auto it = population.find(2 * i + b);
    if (it != population.end() && it->second > 0)
      i = 2 * i + b;
    else
      i = 2 * i + !b;
  }
  return i - w;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> key(n);
  for (I &i : key) cin >> i;

  for (I i = 0; i < n; ++i) {
    I a;
    cin >> a, add(a);
  }

  for (I i = 0; i < n; ++i) {
    I k = key[i];
    I x = decide(k);
    add(x, -1);
    cout << (k ^ x) << ' ';
  }
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

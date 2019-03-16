#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, s;
  cin >> n >> s;

  vector<I> differences(n), capacities(s);
  for (I &i : differences) cin >> i;
  for (I &i : capacities) cin >> i;

  I max_difference = *max_element(differences.begin(), differences.end());

  vector<I> partial(n + 1);
  partial[0] = 0;
  partial_sum(differences.begin(), differences.end(), partial.begin() + 1);

  auto jump = [&](I i, I c) {
    I r = 0;
    while (i >= n) {
      r += n;
      i -= n;
    }
    if (partial[n] - partial[i] <= c) {
      c -= partial[n] - partial[i];
      i = 0;
      r += n;
    }
    r += upper_bound(partial.begin(), partial.end(), partial[i] + c) -
         partial.begin() - 1;
    return r;
  };

  for (I capacity : capacities) {
    // Pamiętać o przypadkach:
    // max(differences) > capacity ⇒ nie da się
    // capacity > sum(differences) – powinno nadal działać

    if (max_difference > capacity) {
      cout << "NIE" << '\n';
      continue;
    }

    I min_c = n;
    for (I i = 0; partial[i] < capacity; ++i) {
      I j = jump(i, capacity);
      I c = 1;
      while (j < n + i) {
        j = jump(j, capacity);
        ++c;
      }

      if (c < min_c) min_c = c;
    }
    cout << min_c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

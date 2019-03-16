#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, s;
  cin >> n >> s;

  vector<I> differences(n), capacities(s);
  for (I &i : differences) cin >> i;
  for (I &i : capacities) cin >> i;

  I max_difference = *max_element(differences.begin(), differences.end());

  for (I capacity : capacities) {
    // Skrajne przypadki:
    // max(differences) > capacity ⇒ nie da się
    // capacity > sum(differences) – powinno nadal działać

    if (max_difference > capacity) {
      cout << "NIE" << '\n';
      continue;
    }

    vector<I> moves(n);
    {
      I i = 0, j = 0, s = 0;
      for (i = 0; i < n; ++i) {
        while (j < 2 * n && s <= capacity) {
          s += differences[j % n];
          ++j;
        }

        moves[i] = j - 1;

        s -= differences[i];
      }
    }

    I start = 0;
    for (I i = 0; i < n; ++i) {
      start = moves[start] % n;
    }

    auto jump = [&](I i) { return i - i % n + moves[i % n]; };
    I c = 1;
    for (I end = jump(start); end < n + start; end = jump(end)) {
      ++c;
    }
    cout << c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

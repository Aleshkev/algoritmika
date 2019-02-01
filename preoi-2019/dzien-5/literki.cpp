#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string s;
  cin >> s;
  I n = s.size(), k;
  cin >> k;

  I best_l = n + 1, best_i = -1, best_j = -1;

  I different = 0;
  vector<I> count(26);
  I j = 0;
  for (I i = 0; i < n; ++i) {
    while (j < n && different < k) {
      if (count[s[j] - 'a']++ == 0) ++different;
      ++j;
    }

    if (different >= k && j - i < best_l) {
      best_l = j - i;
      best_i = i, best_j = j;
    }

    if (--count[s[i] - 'a'] == 0) --different;
  }

  if (best_l > n) {
    cout << "BRAK" << '\n';
  } else {
    cout << best_i + 1 << ' ' << best_j << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

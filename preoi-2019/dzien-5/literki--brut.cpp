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
  for (I i = 0; i < n; ++i) {
    for (I j = i + 1; j <= n && j - i < best_l; ++j) {
      string u(j - i, '#');
      copy(s.begin() + i, s.begin() + j, u.begin());
      sort(u.begin(), u.end());
      u.erase(unique(u.begin(), u.end()), u.end());
      if (u.size() >= k) {
        best_l = j - i;
        best_i = i, best_j = j;
      }
    }
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

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, m;
  cin >> n >> m;

  vector<I> t(n);
  for (I i = 0; i < n; ++i) cin >> t[i], --t[i];

  vector<I> s_at(m + 1), l_at(m + 1);

  for (I i = 1; i < n; ++i) {
    I a = t[i - 1], b = t[i];
    ++s_at[a + 1];
    --s_at[b + 1];
    l_at[b + 1] -= (m - a + b) % m;

    if (a > b) {
      ++s_at[0];
      l_at[0] += (m - a);
    }
  }

  vector<I> s(m + 1);
  partial_sum(s_at.begin(), s_at.end(), s.begin());

  I worst_score = 0;  // If no portal is placed.
  for (I i = 1; i < n; ++i) {
    I a = t[i - 1], b = t[i];
    worst_score += (m - a + b) % m;
  }

  I best_score = worst_score;

  vector<I> l(m + 1);
  for (I i = 0; i < m; ++i) {
    l[i] = (i > 0 ? l[i - 1] + s[i] : 0) + l_at[i];
    best_score = min(best_score, worst_score - l[i] + s[i]);
  }
  cout << best_score << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;
const I inf = 1e9;

#define propose(A, B) A = min(A, B)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, n_1, n_2;
  cin >> n >> n_1 >> n_2;

  I m_1 = 0, m_2 = 0;
  vector<vector<I>> v(n_1 + n_2, vector<I>(n));
  for (I i = 0; i < n_1 + n_2; ++i) {
    for (I j = 0; j < n; ++j) cin >> v[i][j];
    if (i < n_1)
      for (I j = 0; j < n; ++j) v[i][j] = -v[i][j];
    partial_sum(v[i].begin(), v[i].end(), v[i].begin());

    I a = *min_element(v[i].begin(), v[i].end()),
      b = *max_element(v[i].begin(), v[i].end());
    if (a < 0) m_2 -= a;
    if (b > 0) m_1 += b;
  }

  I max_a = max(m_1, m_2) + 10;

  vector<I> t(2 * max_a + 1, inf), d(2 * max_a + 1, inf);
  t[max_a + 0] = 0;

  auto add_item = [&](I weight, I cost) {
    for (I j = -max_a; j <= max_a; ++j) {
      if (t[max_a + j] == inf) continue;
      if (j + weight < -max_a || j + weight > max_a) exit(21);

      propose(d[max_a + j + weight], t[max_a + j] + cost);
    }
  };

  for (I i = 0; i < n_1 + n_2; ++i) {
    fill(d.begin(), d.end(), inf);

    add_item(0, n);
    for (I j = 0; j < n; ++j) add_item(v[i][j], n - j - 1);

    swap(t, d);
  }

  I min_c = t[max_a];

  cout << min_c << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

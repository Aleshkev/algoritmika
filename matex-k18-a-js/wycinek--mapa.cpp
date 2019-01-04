#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, s;
  cin >> n >> s;

  unordered_map<I, I> m;
  m[0] = -1;

  I l = 0, c = 0;

  for (I i = 0; i < n; ++i) {
    I e;
    cin >> e;
    c += e;

    I needed = c - s;

    if (m.count(needed)) {
      l = max(l, i - m[needed]);
    }

    if (!m.count(c)) {
      m[c] = i;
    }
  }

  if (l == 0)
    cout << "BRAK" << '\n';
  else
    cout << l << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> a(n);
  for (I &i : a) cin >> i;
  vector<I> a_partial(n);
  partial_sum(a.begin(), a.end(), a_partial.begin());

  set<II> r;
  I s = 0;
  for (I i = 0; i < n; ++i) {
    I b;
    cin >> b;
    if (s + b <= a_partial[i]) {
      s += b, r.insert({b, i});
    } else if (!r.empty() && r.rbegin()->first > b) {
      s -= r.rbegin()->first, r.erase(*r.rbegin());
      s += b, r.insert({b, i});
    }
  }

  cout << r.size() << '\n';
  vector<I> seconds;
  for (II i : r) seconds.push_back(i.second);
  sort(seconds.begin(), seconds.end());
  for (I i : seconds) cout << i + 1 << ' ';
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
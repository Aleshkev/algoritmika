#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  n = s.size();

  I i = 0, j = n - k;
  set<pair<char, I>> q;
  for (I l = i; l < j; ++l) q.insert({s[l], l});

  string z;

  for (;;) {
    while (!q.empty() && q.begin()->second < i) q.erase(q.begin());
    if (q.empty()) break;

    auto p = *q.begin();

    if (s[j] < p.first) break;

    z += p.first;
    i = p.second + 1;

    q.insert({s[j], j}), ++j;
  }
  for (I l = j; l < n; ++l) z += s[l];
  cout << z << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

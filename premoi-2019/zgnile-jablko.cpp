#include <bits/stdc++.h>

using namespace std;

typedef uintmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string s, k_str;
  cin >> s >> k_str;

  if (k_str == "0" || k_str[0] == '-') exit(101);
  if (s.size() > 2e6) exit(102);

  string pow_10_666(667, '0');
  pow_10_666[0] = '1';
  if (!(k_str.size() < pow_10_666.size() || k_str <= pow_10_666)) exit(103);

  I k = 0;
  for (I i = 0; i < k_str.size(); ++i) {
    k = (k * 10 + k_str[i] - '0') % s.size();
  }

  rotate(s.begin(), s.begin() + k % s.size(), s.end());

  cout << s << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  vector<bool> t(31);
  for (I i = 0; i < 19; ++i) {
    I n;
    cin >> n;
    t[n % 31] = true;
  }
  cout << count(t.begin(), t.end(), true) << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

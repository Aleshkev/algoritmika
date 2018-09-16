#include <bits/stdc++.h>

using namespace std;

typedef int_fast32_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  string s;
  cin >> n >> s;
  n = s.size();

  vector<bool> arm(n + 1);
  for (I i = 0; i < n; ++i) {
    if (s[i] == 'S') {
      arm[i] = arm[i + 1] = true;
    } else if (s[i] == 'L') {
      arm[i] = arm[i + 2] = true;
      ++i;  // Skip next chair, should be L.
    }
  }

  // for (I i = 0; i <= n; ++i) {
  //   if (arm[i]) cout << '*';
  //   if (i < n) cout << s[i];
  // }
  // cout << endl;

  I without_arm = 0;
  for (I i = 0; i < n; ++i) {
    if (arm[i]) {
      arm[i] = false;
    } else if (arm[i + 1]) {
      arm[i + 1] = false;
    } else {
      ++without_arm;
    }
  }

  cout << (n - without_arm) << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  I max_l = 0;
  for (I i = 0; i < s.size(); ++i) {
    I l = 0;
    while (i < s.size() && s[i] == 'a') {
      ++l;
      ++i;
    }
    max_l = max(max_l, l);
  }
  if (max_l > 0)
    cout << string(max_l, 'a') << endl;
  else
    cout << "BRAK" << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

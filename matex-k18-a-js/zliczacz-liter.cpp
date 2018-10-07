#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;
  cin.ignore();

  I occurences[128] = {0};
  for (I i = 0; i < n; ++i) {
    string s;
    getline(cin, s);

    for (char c : s) {
      ++occurences[c];
    }
  }

  for (char c = 'a'; c <= 'z'; ++c) {
    if (occurences[c] > 0) cout << c << ' ' << occurences[c] << '\n';
  }
  for (char c = 'A'; c <= 'Z'; ++c) {
    if (occurences[c] > 0) cout << c << ' ' << occurences[c] << '\n';
  }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

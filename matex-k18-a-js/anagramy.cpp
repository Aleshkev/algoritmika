#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  cout << (a == b ? "TAK" : "NIE") << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

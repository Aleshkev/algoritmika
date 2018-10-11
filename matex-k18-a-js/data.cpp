#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

bool leap(I y) { return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I d, m, y;
  cin >> d >> m >> y;

  vector<I> days = {31, (leap(y) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30,
                    31};
  cout << (d <= days[m - 1] ? "TAK" : "NIE") << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

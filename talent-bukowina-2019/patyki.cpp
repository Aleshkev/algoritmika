#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  map<I, I> d;
  for (I i = 0; i < n; ++i) {
    I l;
    cin >> l;
    ++d[l];
  }

  I c = 0;
  for (auto &i : d) {
    if (i.second > 1) {
      d[i.first * 2] += i.second / 2;
      i.second %= 2;
    }
    c += i.second;
  }

  cout << c << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I w, h;
  cin >> w >> h;

  vector<II> v(w - 1 + h - 1);
  for (I i = 0; i < w - 1; ++i) {
    cin >> v[i].first;
    v[i].second = 0;
  }
  for (I i = 0; i < h - 1; ++i) {
    cin >> v[w - 1 + i].first;
    v[w - 1 + i].second = 1;
  }
  sort(v.begin(), v.end(), greater<II>());
  I c = 0;
  vector<I> tim(2);
  for (II i : v) {
    c += i.first * (tim[(i.second + 1) % 2] + 1);
    ++tim[i.second];
  }
  cout << c << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

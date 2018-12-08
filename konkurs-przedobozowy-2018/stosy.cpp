#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I a, b;
  cin >> a >> b;

  cout << (abs(a - b) < 2 ? "Bob" : "Alicja") << '\n';

  // map<I, map<I, bool>> wins;

  // function<bool(I, I)> is_winning = [&](I x, I y) {
  //   if (wins[x].find(y) != wins[x].end()) {
  //     return wins[x][y];
  //   }

  //   wins[x][y] = false;
  //   for (I i = 1; i <= x / 2; ++i) {
  //     if (!is_winning(x - 2 * i, y + i)) {
  //       wins[x][y] = true;
  //       break;
  //     }
  //   }
  //   if (!wins[x][y])
  //     for (I i = 1; i <= y / 2; ++i) {
  //       if (!is_winning(x + i, y - 2 * i)) {
  //         wins[x][y] = true;
  //         break;
  //       }
  //     }
  //   return wins[x][y];
  // };

  // cout << is_winning(a, b) << endl;

  // for (I i = 0; i < 20; ++i) {
  //   for (I j = 0; j < 20; ++j) {
  //     is_winning(i, j);
  //   }
  // }

  // for (auto &i : wins) {
  //   for (auto &j : i.second) {
  //     cout << setw(2) << i.first << ' ' << setw(2) << j.first << ": "
  //          << j.second << endl;
  //   }
  // }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

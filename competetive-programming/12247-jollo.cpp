// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=611&page=show_problem&problem=3399
#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (;;) {
    I a0, a1, a2, b0, b1;
    cin >> a0 >> a1 >> a2 >> b0 >> b1;
    if (a0 == 0) break;
    set<I> a = {a0, a1, a2};

    I won = 0;
    for (I i : b) {
      bool lost = false;
      for (I j : a) {
        if (i < j) {
          a.erase(j);
          lost = true;
          break;
        }
      }
      if (lost) continue;

      ++won;
      a.erase(a.begin());
    }

    for (I i : a) cout << i << ' ';
    cout << endl;

    I x = *a.begin();
    for (; x <= 52; ++x) {
      if (x == a0 || x == a1 || x == a2 || x == b0 || x == b1) {
        continue;
      }
      break;
    }

    if (x <= 52 && won > 0) {
      cout << x << '\n';
    } else {
      cout << "-1\n";
    }
  }

  cout << endl;
  system("pause");
  return 0;
}

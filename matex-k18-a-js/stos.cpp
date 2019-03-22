#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  // Ten kod jest bardzo optymalny, ponieważ używa wielomianowo więcej wektorów
  // niż pojedynczy stos.

  I max_x = 100;
  vector<vector<I>> indices(max_x + 1);

  I q, c = 0;
  cin >> q;
  while (q--) {
    char o;
    cin >> o;
    if (o == '+') {
      I x;
      cin >> x;
      indices[x].push_back(c++);
    } else {
      --c;
      for (I x = 1; x <= max_x; ++x) {
        if (!indices[x].empty() && indices[x].back() == c) {
          indices[x].pop_back();
          cout << x << '\n';
          break;
        }
      }
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

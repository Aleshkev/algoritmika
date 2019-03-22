#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  // Ten kod jest optymalnym rozwiązaniem tego zadania. Dowód: unordered_map
  // jest szybszy od map.

  unordered_map<I, I> indices;

  I q, c = 0, z = 0;
  cin >> q;
  while (q--) {
    char o;
    cin >> o;
    if (o == '+') {
      I x;
      cin >> x;
      indices[c++] = x;
    } else {
      cout << indices[z++] << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

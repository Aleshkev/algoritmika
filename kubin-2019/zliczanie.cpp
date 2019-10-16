#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> v(n);
  for (I &i : v) cin >> i;

  // Nie jest kwadratowe, ponieważ w każdym momencie trzymamy tylko gcd
  // przedziałów zawierających obecną pozycję, a takich jest najgorzej
  // logarytmicznie wiele.
  //
  // Z tego powodu można to zrobić też dla każdej pozycji binsearchując jakie są
  // i po ile te różne gcd, używając tabeli potęgowej żeby w O(1) odpowiadać na
  // zapytania o gcd na przedziale.
  map<I, I> c, r;
  for (I i = 0; i < n; ++i) {
    auto z = c;
    c.clear();
    for (auto xy : z) {
      c[__gcd(xy.first, v[i])] += xy.second;
    }
    ++c[v[i]];
    for (auto xy : c) r[xy.first] += xy.second;
  }

  I q;
  cin >> q;
  while (q--) {
    I x;
    cin >> x;
    cout << r[x] << "\n";
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

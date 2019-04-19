#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;
  cin.ignore();
  for (I i = 0; i < q; ++i) {
    string ln;
    getline(cin, ln);
    istringstream is(ln);
    vector<I> v;
    I x;
    while (is >> x) v.push_back(x);

    cout << "Case " << i + 1 << ": " << *max_element(v.begin(), v.end())
         << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
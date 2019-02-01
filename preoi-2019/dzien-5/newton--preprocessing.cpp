#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  const I p = 1e9 + 7;

  vector<I> v = {1};
  I c = 1;
  for (I i = 1; i < p; ++i) {
    c = c * i % p;
    if (i % (I)1e5 == 0) {
      v.push_back(c);
    }
  }

  cout << "[";
  for (I i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i != v.size() - 1) cout << ",";
  }
  cout << "]\n";

#ifdef UNITEST
  cout.flush();
  // system("pause");
#endif
  return 0;
}

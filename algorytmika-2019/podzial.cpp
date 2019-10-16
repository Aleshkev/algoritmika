#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  []() {
    I n;
    cin >> n;
    vector<I> v(n);
    for (I &i : v) cin >> i;

    I s = accumulate(v.begin(), v.end(), 0);
    if (s % 2 == 1) {
      cout << "NIE\n";
      return;
    }
    s /= 2;

    vector<vector<I>> d(s + 1);
    for (I i = 0; i < n; ++i) {
      I w = v[i];
      for (I j = s - w; j >= 0; --j) {
        if ((!d[j].empty() || j == 0) && d[j + w].empty()) {
          d[j + w] = d[j];
          d[j + w].push_back(i);
        }
      }
    }

    auto a = d[s];
    if (a.empty()) {
      cout << "NIE\n";
      return;
    }

    vector<I> b(n);
    iota(b.begin(), b.end(), 0);
    b.resize(set_difference(b.begin(), b.end(), a.begin(), a.end(), b.begin()) -
             b.begin());

    cout << "TAK\n";
    cout << a.size() << " ";
    for (I i : a) cout << i + 1 << " ";
    cout << "\n" << b.size() << " ";
    for (I i : b) cout << i + 1 << " ";
    cout << "\n";
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

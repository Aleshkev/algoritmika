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

    sort(v.begin(), v.end());

    I m = *max_element(v.begin(), v.end());
    vector<I> c(m + 1);
    for (I i : v) ++c[i];

    for (I i : c) {
      if (i % 2 == 1) {
        cout << "Andrzej" << '\n';
        return;
      }
    }
    cout << "Blazej" << '\n';
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  []() {
    I n, s;
    cin >> n >> s;

    vector<I> v(n);
    for (I& i : v) cin >> i;
    I m = *min_element(v.begin(), v.end());
    I c = 0;
    for (I& i : v) {
      c += i - m;
      i -= m;
    }
    if (c >= s) {
      cout << m << '\n';
      return;
    }

    cout << max((I)-1, m - (s - c + n - 1) / n) << '\n';
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

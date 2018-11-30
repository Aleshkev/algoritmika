#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I lower(const vector<I> &v, I x) {
  I lo = 0, hi = v.size();
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (v[mid] < x) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}
I upper(const vector<I> &v, I x) {
  I lo = 0, hi = v.size();
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (v[mid] <= x) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;
  sort(v.begin(), v.end());

  I q;
  cin >> q;
  while (q--) {
    I x;
    cin >> x;
    cout << upper(v, x) - lower(v, x) << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

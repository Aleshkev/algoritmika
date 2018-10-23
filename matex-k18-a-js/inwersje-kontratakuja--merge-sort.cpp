#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

pair<vector<I>, I> _count_inversions(const vector<I> &v) {
  if (v.size() <= 1) {
    return {v, 0};
  }

  vector<I> l(v.begin(), v.begin() + v.size() / 2),
      r(v.begin() + v.size() / 2, v.end());

  I l_c, r_c;
  tie(l, l_c) = _count_inversions(l);
  tie(r, r_c) = _count_inversions(r);
  I c = l_c + r_c;
  for (I i : r) {
    c += l.end() - upper_bound(l.begin(), l.end(), i);
  }

  vector<I> w(v.size());
  merge(l.begin(), l.end(), r.begin(), r.end(), w.begin());

  return {w, c};
}
I count_inversions(const vector<I> &v) { return _count_inversions(v).second; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;
  vector<I> v(n);
  for (I &i : v) cin >> i;

  cout << count_inversions(v) << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

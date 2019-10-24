#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
const I inf = 1e18;

struct tree {
  vector<I> d00, d01, d10, d11;
  I w;
  tree(I n) : w(1 << __lg(n) << 1) {
    d00.assign(2 * w, 0);
    d01 = d10 = d11 = d00;
  }
  void set(I i, bool is_1) {
    i += w;
    if (is_1)
      d00[i] = 0, d11[i] = 1;
    else
      d00[i] = 1, d11[i] = 0;

    for (i /= 2; i > 0; i /= 2) {
      I a = 2 * i, b = 2 * i + 1;
#define ip(X, Y) (X > 0 && Y > 0 ? X + Y : -inf)
      d00[i] = max({d00[a], d00[b], ip(d01[a], d00[b]), ip(d00[a], d10[b])});
      d01[i] = max({d01[a], d01[b], ip(d01[a], d01[b]), ip(d00[a], d11[b])});
      d10[i] = max({d10[a], d10[b], ip(d11[a], d00[b]), ip(d10[a], d10[b])});
      d11[i] = max({d11[a], d11[b], ip(d11[a], d01[b]), ip(d10[a], d11[b])});
    }
  }
  I get_all() { return max({d00[1], d01[1], d10[1], d11[1]}); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n, m;
  cin >> n >> m;
  tree t(n);
  string s;
  cin >> s;
  for (I i = 0; i < n; ++i) {
    t.set(i, s[i] == '1');
  }
  cout << t.get_all() << " ";
  while (m--) {
    I i;
    cin >> i;
    --i;
    t.set(i, t.d00[t.w + i] > 0);
    cout << t.get_all() << " ";
  }
  cout << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

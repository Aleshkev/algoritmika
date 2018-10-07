#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I in_range(I a, I b, I c, I x) {
  if (a / c == b / c) return (a % c <= x && x <= b % c);
  return (x >= a % c) + (x <= b % c);
}

I for_x(I a, I b, I c, I x) { return pow(x, in_range(a, b, c, x)); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I a, b, c;  // a <= b (inaczej niż w treści zadania)
  cin >> b >> a >> c;
  ++a;

  I s = 1;
  for (I x = 0; x < c; ++x) {
    s *= for_x(a, b, c, x);
    s %= c;
  }
  cout << s << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

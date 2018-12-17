#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I ones_up_to(I x) {
  ++x;
  I c = 0;
  for (I b = 0; b < 30; ++b) {
    I l = x % (1 << b << 1);
    c += (x - l) / 2;
    c += max((I)0, l - (1 << b));
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I a, b;
  cin >> a >> b;

  cout << ones_up_to(b) - (a > 0 ? ones_up_to(a - 1) : 0) << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}
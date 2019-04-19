#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  for (;;) {
    F h, u, d, f;
    cin >> h >> u >> d >> f;
    if (h == 0) break;

    F step = u, decrease = u * f / 100.0, slide = d, position = 0, target = h;
    bool ok = false;
    I i = 0;
    for (;;) {
      if (step > 0) position += step;
      step -= decrease;
      if (position > target) {
        ok = true;
        break;
      }
      position -= slide;
      if (position < 0) {
        ok = false;
        break;
      }
      ++i;
    }
    cout << (ok ? "success" : "failure") << " on day " << i + 1 << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
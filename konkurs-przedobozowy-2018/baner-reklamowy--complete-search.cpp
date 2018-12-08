#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, p;
  cin >> n >> p;

  vector<I> heights(n);
  for (I i = 0; i < n; ++i) cin >> heights[i];

  I c = 0;
  for (I i = 0; i < n; ++i) {
    for (I w = 1; i + w <= n && w <= p; ++w) {
      I needed_h = (p + w - 1) / w;
      I available_h =
          *min_element(heights.begin() + i, heights.begin() + i + w);
      if (needed_h <= available_h) {
        c += available_h - needed_h + 1;
      }
    }
  }

  cout << c << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

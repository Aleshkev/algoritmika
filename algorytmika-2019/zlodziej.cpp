#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

#define propose(A, B) A = max(A, B)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  const I max_b = 1e5;
  I n, b;
  cin >> n >> b;

  vector<I> weights(n), values(n);
  for (I i = 0; i < n; ++i) cin >> weights[i];
  for (I i = 0; i < n; ++i) cin >> values[i];

  auto with_item = [&](vector<I> v, I weight, I value) {
    for (I j = b - weight; j >= 0; --j) {
      if (v[j] == 0 && j > 0) continue;
      propose(v[j + weight], v[j] + value);
    }
    return v;
  };

  vector<vector<I>> left(n, vector<I>(b + 1));
  left[0][weights[0]] = values[0];
  for (I i = 1; i < n; ++i)
    left[i] = with_item(left[i - 1], weights[i], values[i]);

  vector<vector<I>> right(n, vector<I>(b + 1));
  right[n - 1][weights[n - 1]] = values[n - 1];
  for (I i = n - 2; i >= 0; --i)
    right[i] = with_item(right[i + 1], weights[i], values[i]);

  for (I i = 0; i < n; ++i)
    for (I j = 1; j <= b; ++j) left[i][j] = max(left[i][j], left[i][j - 1]);
  for (I i = 0; i < n; ++i)
    for (I j = 1; j <= b; ++j) right[i][j] = max(right[i][j], right[i][j - 1]);

  for (I i = 0; i < n; ++i) {
    I best = 0;
    for (I j = 0; j <= b; ++j) {
      best = max(best, (i > 0 ? left[i - 1][j] : 0) +
                           (i < n - 1 ? right[i + 1][b - j] : 0));
    }
    cout << best << " ";
  }
  cout << "\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

const size_t MAX_M = 256;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  uint32_t n, q;
  cin >> n >> q;

  const size_t Q = ceil(sqrt(n)) + 1;

  vector<int32_t> A(n);
  vector<vector<int32_t>> S(MAX_M, vector<int32_t>(Q + 1, 1));

  for (uint32_t i = 0; i < n; i++) {
    cin >> A[i];
    for (uint32_t m = 1; m < MAX_M; m++) S[m][i / Q] *= A[i], S[m][i / Q] %= m;
  }

  while (q-- > 0) {
    uint32_t x, y;
    int64_t m;
    cin >> x >> y >> m;
    x--;
    y--;

    int64_t r = 1;
    for (uint32_t i = x; i <= y; i++) {
      if (n > 4 and i % Q == 0 and i + Q - 1 <= y)
        r *= int64_t(S[m][i / Q]);
      else
        r *= int64_t(A[i]);
      r %= m;
    }
    cout << r << "\n";
  }
}

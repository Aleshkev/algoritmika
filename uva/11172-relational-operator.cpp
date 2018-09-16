#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  for (I i = 0; i < n; ++i) {
    I a, b;
    cin >> a >> b;
    cout << (a < b ? '<' : (a > b ? '>' : '=')) << '\n';
  }

  return 0;
}

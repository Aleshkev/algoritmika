#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> v(10);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++v[x % 10];
  }

  int c = v[0] * (v[0] - 1) / 2 + v[5] * (v[5] - 1) / 2;
  for (int i = 1; i < 5; ++i) {
    c += v[i] * v[10 - i];
  }
  cout << c << "\n";

  return 0;
}

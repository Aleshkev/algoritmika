#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string a, b;
  cin >> a >> b;

  vector<string> alphabet = {"2", "3",  "4", "5", "6", "7", "8",
                             "9", "10", "J", "D", "K", "A"};

  I a_i = find(alphabet.begin(), alphabet.end(), a) - alphabet.begin();
  I b_i = find(alphabet.begin(), alphabet.end(), b) - alphabet.begin();

  cout << (a_i > b_i ? "A" : a_i < b_i ? "B" : "R") << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I mod = 1e9 + 7, n;
string s;
I i = 0;

I expression() {
  if (isdigit(s[i])) {
    // Zjadamy liczbę.
    I number = 0;
    while (i < n && isdigit(s[i])) {
      number = (number * 10 + s[i++] - '0') % mod;
    }
    return number;
  }

  // Jeżeli nie liczbę, to zjadamy wyrażenie w nawiasie.

  assert(s[i] == '('), ++i;

  I ans = expression();

  while (s[i] != ')') {
    assert(s[i] == '#'), ++i;

    I x = expression();
    ans = (2 * ans + x) % mod;
  }

  assert(s[i] == ')'), ++i;

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string z;
  getline(cin, z);

  // 1. Zmieniamy x na (x), żeby funkcja na pewno zadziałała.
  // 2. Usuwamy białe znaki.
  s += "(";
  for (char c : z)
    if (c != ' ') s += c;
  s += ")";
  n = s.size();

  cout << expression() << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

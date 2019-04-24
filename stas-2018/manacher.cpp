#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

#define min(a, b) (a < b ? a : b)
template <I w>
void manacher(char *s, I n, I *d) {
  for (I i = 0, l = 0, r = -1; i < n; ++i) {
    I k = (i > r ? 1 - w : min(d[l + r - i + w], r - i + 1));
    while (i - k - w >= 0 && i + k < n && s[i - k - w] == s[i + k]) ++k;
    d[i] = k--;
    if (i + k > r) l = i - k - w, r = i + k;
  }
}
#define manacher_odd manacher<0>
#define manacher_even manacher<1>

#ifdef UNITEST
#define g getchar
#define p putchar
#else
#define g getchar_unlocked
#define p putchar_unlocked
#endif

#define if_integral(X) typename enable_if<is_integral<T>::value, X>::type

struct blitz_aus {
  char eat_blank() {
    char c = g();
    while (isblank(c)) c = g();
    return c;
  }
  template <typename T>
  if_integral(blitz_aus &) operator>>(T &x) {
    x = 0;
    for (char c = eat_blank(); isdigit(c); c = g()) x = 10 * x + c - '0';
    return *this;
  }
  blitz_aus &operator>>(char *s) {
    for (char c = eat_blank(); islower(c); c = g()) *(s++) = c;
    *s = '\0';
    return *this;
  }
  blitz_aus &operator<<(char c) {
    p(c);
    return *this;
  }
  template <typename T>
  if_integral(blitz_aus &) operator<<(T x) {
    if (x == 0)
      p('0');
    else {
      char d[20];
      int32_t i = 0;
      for (; x > 0; x /= 10) d[i++] = '0' + x % 10;
      for (--i; i >= 0; --i) p(d[i]);
    }
    return *this;
  }
};

int main() {
  blitz_aus io;
  I n;
  const I max_n = 1e5;
  static char s[max_n];
  io >> n >> s;

  static I odd[max_n], even[max_n];
  manacher_odd(s, n, odd);
  manacher_even(s, n, even);
  for (I i = 0; i < n; ++i) io << odd[i] << ' ';
  io << '\n';
  for (I i = 1; i < n; ++i) io << even[i] << ' ';
  io << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
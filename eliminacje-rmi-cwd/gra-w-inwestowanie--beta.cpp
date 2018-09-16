#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I n, k;

bool check(I t, I z) {
  I span = (t - z * k) / (z + 1), wspans = (t - z * k) % (z + 1);

  I c = 1, x = span;
  if (x >= n) return true;
  for (I i = 1; i < z + 1; ++i) {
    c = x;
    x = c * span;
    if (wspans) x += c, --wspans;
    if (x >= n) return true;
  }

  return false;
}

bool check_t(I t) {
  // Eh, ta funkcja najwyraźniej jest dostatecznie szybka. Nie mam pojęcia jaką
  // dokładnie ma złożoność, więc chciałem to "zoptymalizować" na podstawie paru
  // "obserwacji".
  //
  // To był jeden z najgorszych błędów. Po contescie dowiedziałem się, że *ten*
  // kod dostaje 100 punktów mimo mysterialnej złożoności czasowej. Z kolei po
  // moich "optymalizacjach" dostaje 25 punktów ze złymi odpowiedziami.
  //
  // Ten contest to były eliminacje na MIĘDZYNARODOWĄ OLIMPIADĘ INFORMATYCZNĄ
  // RMI ("Seniorów", czyli polskich licealistów)!! I gdybym miał te 100 punktów
  // byłbym DRUGI W RANKINGU!! JAKO UCZEŃ 1. KLASY!!
  //
  // No cóż, kiedyś będę ekspertem od zmarnowanych życiowych szans.

  for (I z = 0; z <= t / (k + 2); ++z) {
    if (check(t, z)) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  I lo = 0, hi = n + 1;
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (check_t(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << '\n';

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}
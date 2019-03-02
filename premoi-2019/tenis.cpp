#include <iostream>

using namespace std;

typedef intmax_t I;

// Okazuje się, że mecz tenisa spełnia prostą gramatykę.
//
// Do tego, dzięki pewnej zaskakującej cesze do jej rozwiązania nie trzeba
// używać FFT: wystarczy prosty parser Pratta. Poniższa implementacja w O(n)
// wykorzystuje nieudowodnione twierdzenie Eulera, jednak przetestowane dla
// n < 10^7.
//
// Zadanie da się zrobić prościej wyobrażając sobie mecz jako graf, w którym
// można w łatwy i przyjemny sposób znaleźć minimalne przepływy.

string s;
I i = 0;

bool gem(I win = 4) {
  I a = 0, b = 0;
  for (;;) {
    (s[i++] == 'A') ? ++a : ++b;

    if (a >= win && a >= b + 2) return true;
    if (b >= win && b >= a + 2) return false;
  }
}

bool set() {
  I a = 0, b = 0;
  for (;;) {
    gem() ? ++a : ++b;

    if (a == b && b == 6) return gem(7);
    if (a >= 6 && a >= b + 2) return true;
    if (b >= 6 && b >= a + 2) return false;
  }
}

bool match() {
  I a = 0, b = 0;
  for (;;) {
    set() ? ++a : ++b;

    if (a == 2) return true;
    if (b == 2) return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> s;

  cout << (match() ? "A" : "B") << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

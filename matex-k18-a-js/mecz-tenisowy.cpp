#include <iostream>

using namespace std;

typedef intmax_t I;

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

    if (a == 3) return true;
    if (b == 3) return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;

  cout << (match() ? "A" : "B") << endl;

  // Or you could do s.back() IF YOU WANT TO DO IT THE EASY WAY. MONSTER.

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

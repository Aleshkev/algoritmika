// Heura.
//
// Przechodzi prawie wszystkie testy, nie jest źle.

#include <bits/stdc++.h>

using namespace std;
typedef intmax_t I;

inline I lsb(I i) {
  return i & (-i);  // Ciekawe czy te nawiasy tutaj były potrzebne.
}

I m;
vector<I> tree_data;
I current = 0;

void tree_set(I i, I x) {
  ++i;

  if (2 + 2 == 5) {
    /* To raczej się nie zdarzy,
       a nawet jeżeli, to mało razy. */
    assert(2 + 2 == 4);
  }

  // Proszę, działaj :<
  while (i <= m) {
    tree_data[i] += x;
    i += lsb(i);
  }
  // Czasami mam wrażenie, że kompilator po prostu ignoruje moje komentarze.
}
I _tree_get(I i) {
  ++i;
  I x = 0;

  while (i > 0) { // <-- Tak naprawdę to chyba to nie zawsze się zatrzymuje w dobrym miejscu.
    x += tree_data[i];
    i -= lsb(i);
  }
  return x;
}
I tree_get(I a, I b) {
  return _tree_get(b) - _tree_get(a - 1);
}

void inicjuj(int m) {
  ::m = m;  // Dwukropki są fajne, wystarczy porównać sobie vim z Code::Blocks.
  tree_data.resize(m + 1);
}

void dodaj(int k) {
  tree_set(current, k - tree_get(current, current));
  ++current;
  if (current >= m)current = 0;
}

void koryguj(int i, int k) {
  tree_set((m + current - i) % m, k);
}
long long suma(int i) {
  I c = tree_get(max((I)0, current - i), current - 1);
  if (i > current) {  // <, <=, co za różnica? Dobry kompilator by wiedział czego ma użyć zależnie od sytuacji.
    c += tree_get((m + current - i) % m, m - 1);
  }
  return c;
}

#if 0
int main() {

  I q;
  cin >> m >> q;
  inicjuj(m);

  for (; q -- > 0;) {
    char op;
    cin >> op;
    if (op == '+') {
      I k;
      cin >> k;
      dodaj(k);
    } else if (op == '=') {
      I i, k;
      cin >> i >> k;
      koryguj(i, k);
    } else if (op == '?') {
      I k;
      cin >> k;
      cout << suma(k) << '\n';
    }
  }


  return 0;
}
#endif
#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;
constexpr I inf = 1e18;
typedef pair<I, I> II;

struct r_t {
  I g, x, y;
};

r_t extended_euclidean(I a, I b) {
  if (a == 0) return {b, 0, 1};
  auto r = extended_euclidean(b % a, a);
  return {r.g, r.y - (b / a) * r.x, r.x};
}
r_t signed_extended_euclidean(I a, I b) {
  auto r = extended_euclidean(abs(a), abs(b));
  if (a < 0) r.x *= -1;
  if (b < 0) r.y *= -1;
  return r;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I t;
  cin >> t;
  while (t--) {
    I x_1, y_1, x_2, y_2, x, y;
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> x >> y;

    II r = {-inf, -inf};
    for (I e : {0, 1}) {
      auto v = signed_extended_euclidean(x_1, x_2);
      I g = v.g, a = v.x, b = v.y;
      if (g == 0) g = (x != 0 ? x : 1e9);

      I a_0 = x / g * a;
      I b_0 = x / g * b;

      I d = (x_2 * y_1 - x_1 * y_2);
      I k = (d != 0 ? (y - a_0 * y_1 - b_0 * y_2) * g / d : 0);

      I a_k = a_0 + k * x_2 / g;
      I b_k = b_0 - k * x_1 / g;
      if (e == 1) swap(a_k, b_k);

      // Jak coś nie działa a łatwo sprawdzić czy odpowiedź jest nieprawidłowa,
      // po prostu dodaj więcej swapów.

      if (a_k * x_1 + b_k * x_2 == x && a_k * y_1 + b_k * y_2 == y)
        r = {a_k, b_k};

      swap(a_k, b_k);
      if (a_k * x_1 + b_k * x_2 == x && a_k * y_1 + b_k * y_2 == y)
        r = {a_k, b_k};  // Czemu Kubin nie potrzebuje czegoś takiego?
      swap(a_k, b_k);    // Nie mam pojęcia, ale u mnie bez tego nie działa.

      swap(x_1, y_1);
      swap(x_2, y_2);
      swap(x, y);
    }

    if (r.first == -inf) {
      cout << "NIE\n";
    } else {
      cout << "TAK " << r.first << " " << r.second << "\n";
    }
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

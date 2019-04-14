#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    o << *i;
    if (i != prev(v.end())) o << ", ";
  }
  o << "]";
  return o;
}

struct pt {
  I x, y;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);

  I n, q;
  cin >> n >> q;

  auto segment_sum = [](I start, I length, I a, I b) {
    return (b - a + 1) * start + b * (b + 1) / 2 -
           (a == 0 ? 0 : (a - 1) * a / 2);
  };

  while (q--) {
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    bool asc = true;
    pt at = {1, 0};
    while (true) {
      I horizontal_y = at.y, horizontal_a, horizontal_b;
      I vertical_x, vertical_a, vertical_b;
      if (asc) {
        horizontal_y
      }
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

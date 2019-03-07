#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
int32_t sign(T x) {
  return x < 0 ? -1 : x > 0;
}

struct point {
  int32_t x, y;
  point operator-(const point &p) const { return {x - p.x, y - p.y}; }
  int64_t operator^(const point &p) const {
    return (int64_t)x * (int64_t)p.y - (int64_t)p.x * (int64_t)y;
  }
};
struct segment {
  point a, b;
  int32_t ccw(const point &p) const { return sign((b - a) ^ (p - a)); }
  bool contains(const point &p) const {
    return ccw(p) == 0 && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
  }
  bool intersects(const segment &s) const {
    return (ccw(s.a) != ccw(s.b) && s.ccw(a) != s.ccw(b)) || contains(s.a) ||
           contains(s.b) || s.contains(a) || s.contains(b);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int32_t n;
  cin >> n;
  vector<point> v(n);
  for (auto &p : v) {
    cin >> p.x >> p.y;
  }

  int32_t m;
  cin >> m;

  while (m--) {
    segment alpha;
    cin >> alpha.a.x >> alpha.a.y;
    alpha.b.x = 1e9 + 1, alpha.b.y = alpha.a.y + 1;

    bool on_edge = false;
    for (int32_t i = 0; i + 1 < n; ++i) {
      if (segment{v[i], v[i + 1]}.contains(alpha.a)) {
        on_edge = true;
        break;
      }
    }
    on_edge = (on_edge || segment{v[n - 1], v[0]}.contains(alpha.a));
    if (on_edge) {
      cout << "KRAWEDZ" << '\n';
      continue;
    }

    int32_t intersections = 0;
    for (int32_t i = 0; i + 1 < n; ++i) {
      intersections += alpha.intersects({v[i], v[i + 1]});
    }
    intersections += alpha.intersects({v[n - 1], v[0]});
    cout << (intersections % 2 != 0 ? "WEWNATRZ" : "NA ZEWNATRZ") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

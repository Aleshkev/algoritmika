#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

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

  for (int32_t i = 0; i < n; ++i) {
    segment alpha, beta;
    cin >> alpha.a.x >> alpha.a.y >> alpha.b.x >> alpha.b.y;
    cin >> beta.a.x >> beta.a.y >> beta.b.x >> beta.b.y;
    cout << (alpha.intersects(beta) ? "TAK" : "NIE") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

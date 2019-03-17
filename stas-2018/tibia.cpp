#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Tree {
  I w;
  vector<I> value, for_later;
  Tree(I n) {
    for (w = 1; w < n;) w *= 2;
    value.assign(2 * w, 0);
    for_later.assign(2 * w, 0);
  }

  I query(I qb, I qe, I rb, I re, I i, I x = 0) {
    if (re < qb || rb > qe) return 0;
    if (qb <= rb && re <= qe) {
      value[i] = max(value[i], x);
      for_later[i] = max(for_later[i], x);
      return value[i];
    }

    value[2 * i] = max(value[2 * i], for_later[i]);
    for_later[2 * i] = max(for_later[2 * i], for_later[i]);

    value[2 * i + 1] = max(value[2 * i + 1], for_later[i]);
    for_later[2 * i + 1] = max(for_later[2 * i + 1], for_later[i]);

    for_later[i] = 0;

    I mid = (rb + re) / 2;

    I r = max(query(qb, qe, rb, mid, 2 * i, x),
              query(qb, qe, mid + 1, re, 2 * i + 1, x));

    value[i] = max(value[2 * i], value[2 * i + 1]);
    return r;
  }
  I query(I qb, I qe, I x = 0) { return query(qb, qe, 0, w - 1, 1, x); }
};

// Pronounce /zak/, not /sæk/
struct Sack {
  I x, y, c;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I w, h, n;
  cin >> w >> h >> n;

  vector<Sack> sacks(n);
  for (auto &s : sacks) cin >> s.x >> s.y >> s.c;

  vector<I> ys;
  for (auto &s : sacks) ys.push_back(s.y);
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (auto &s : sacks)
    s.y = lower_bound(ys.begin(), ys.end(), s.y) - ys.begin();
  I max_y = ys.size() - 1;

  sort(sacks.begin(), sacks.end(), [](const Sack &l, const Sack &r) {
    return tie(l.x, l.y) < tie(r.x, r.y);
  });

  Tree tree(max_y + 1);
  for (auto &s : sacks) {
    tree.query(s.y, max_y, tree.query(0, s.y) + s.c);
  }

  cout << tree.query(0, max_y) << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

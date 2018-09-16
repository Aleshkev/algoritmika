#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef int I;

struct State {
  I t, c, x;
};
bool operator<(const State &a, const State &b) {
  return tie(a.t, a.c, a.x) < tie(b.t, b.c, b.x);
}

ostream &operator<<(ostream &o, const State &s) {
  o << "(" << s.t << ' ' << s.c << ' ' << s.x << ")";
  return o;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, k;
  cin >> n >> k;

  set<State> q;
  q.insert(State{0, 1, 0});

  // map<I, map<I, I>> best;

  while (!q.empty()) {
    // for (State i : q) cout << "(" << i.t << ' ' << i.c << ' ' << i.x << ") ";
    // cout << endl;
    // cout << q.size() << ' ';

    I t = q.begin()->t, c = q.begin()->c, x;

    while (!q.empty() && q.begin()->t == t && q.begin()->c == c) {
      x = q.begin()->x;
      q.erase(q.begin());
    }

    // cout << current << endl;

    // best[t][c] = max(best[t][c], x);

    if (x >= n) {
      // cout << "OK" << endl;
      cout << t << '\n';
      break;
    }

    q.insert(State{t + 1, c, x + c});
    q.insert(State{t + k, x, 0});
  }

  // for (auto i : best) {
  //   cout << i.first << ": ";
  //   for (auto j : i.second) cout << "[" << j.first << ": " << j.second << "]
  //   "; cout << endl;
  // }

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif

  return 0;
}

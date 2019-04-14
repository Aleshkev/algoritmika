//   _______                        _             _     _
//  |__   __|                      | |           | |   | |
//     | | ___  _ __  ___  ___  ___| | ___ __ ___| |_  | |_ ___
//     | |/ _ \| '_ \/ __|/ _ \/ _ \ |/ / '__/ _ \ __| | __/ _ \ 
//     | | (_) | |_) \__ \  __/  __/   <| | |  __/ |_  | || (_) |
//     |_|\___/| .__/|___/\___|\___|_|\_\_|  \___|\__|  \__\___/
//             | |
//             |_|
//         _                               _     _            _ _
//        (_)                            /_/    (_)          | | |
//   _ __  _  ___  ___ _______ _______  ___  ___ _  ___    __| | | __ _
//  | '_ \| |/ _ \/ __|_  / __|_  / _ \/ __|/ __| |/ _ \  / _` | |/ _` |
//  | | | | |  __/\__ \/ / (__ / /  __/\__ \ (__| |  __/ | (_| | | (_| |
//  |_| |_|_|\___||___/___\___/___\__ ||___/\___|_|\___|  \__,_|_|\__,_|
//                                 /_/                              _
//                                                                 | |
//  _ __   __ _ ___ _______  __ _  ___    _ __   __ _ _ __ ___   __| |_   _
// | '_ \ / _` / __|_  / _ \/ _` |/ _ \  | '_ \ / _` | '__/ _ \ / _` | | | |
// | | | | (_| \__ \/ /  __/ (_| | (_) | | | | | (_| | | | (_) | (_| | |_| |
// |_| |_|\__,_|___/___\___|\__, |\___/  |_| |_|\__,_|_|  \___/ \__,_|\__,_|
//                           __/ |
//                          |___/

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

#ifdef UNITEST

vector<I> v;
I queries = 0;
pair<int, int> inicjuj() {
  I t, n;
  cin >> t >> n;

  v.resize(n);
  // for (I &i : v) cin >> i;
  srand(time(0));
  for (I &i : v) i = rand() % 5;
  sort(v.begin(), v.end());
  cout << v << endl;

  return {t, n};
}

pair<long long, long long> min_max(long long s, long long t) {
  ++queries;
  I l = *lower_bound(v.begin(), v.end(), s);
  I r = *prev(upper_bound(v.begin(), v.end(), t));
  return {s <= l && l <= t ? l : -1, s <= r && r <= t ? r : -1};
}
void odpowiedz(long long x) {
  I n = v.size(), ans = 0;
  for (I i = 0; i + 1 < n; ++i) {
    ans = max(ans, v[i + 1] - v[i]);
  }
  if (x == ans) {
    cout << "status-ok";
  } else {
    cout << "status-wrong-answer (" << x << " != " << ans << ")";
  }
  cout << " (" << queries << ")" << '\n';
}

#else
#include "cskolib.h"
#endif

int main() {
  I task, n;
  tie(task, n) = inicjuj();

  vector<I> v(n);
  for (I i = 0; n - i - 1 >= i; ++i) {
    // cout << i << ": " << v << endl;
    tie(v[i], v[n - i - 1]) =
        min_max(i > 0 ? v[i - 1] + 1 : 1, i > 0 ? v[n - i] - 1 : 1e18 + 1);
    if (v[i] == -1) v[i] = v[i - 1];
    if (v[n - i - 1] == -1) v[n - i - 1] = v[n - i];
  }
  // cout << v << '\n' << endl;

  I ans = 0;
  for (I i = 0; i + 1 < n; ++i) {
    ans = max(ans, v[i + 1] - v[i]);
  }
  odpowiedz(ans);

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

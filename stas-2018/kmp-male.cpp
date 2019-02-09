#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

vector<I> get_mp(const string &s) {
  I n = s.size() - 1;
  vector<I> mp(n + 1);
  mp[0] = -1;
  for (I i = 1; i <= n; ++i) {
    mp[i] = mp[i - 1] + 1;
    while (mp[i] > 0 && s[mp[i]] != s[i]) {
      mp[i] = mp[mp[i] - 1] + 1;
    }
  }
  return mp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I q;
  cin >> q;
  while (q--) {
    vector<string> patterns;
    vector<vector<I>> mps;

    string patterns_joined, s;
    cin >> patterns_joined >> s;
    for (I i = 0; i < (I)patterns_joined.size(); ++i) {
      I j = i;
      while (j < (I)patterns_joined.size() && patterns_joined[j] != '*') {
        ++j;
      }

      if (j - i > 0) {
        patterns.push_back(string(j - i, ' '));
        copy(patterns_joined.begin() + i, patterns_joined.begin() + j,
             patterns.back().begin());
        patterns.back().insert(patterns.back().begin(), '#');
        mps.push_back(get_mp(patterns.back()));
      }

      i = j;
    }
    I n = s.size();
    s.insert(s.begin(), '$');

    bool found = false;
    if (patterns.size() == 0) {
      found = true;
    } else {
      I p = 0;
      I k = 0;
      for (I i = 1; i <= n; ++i) {
        ++k;
        while (k > 0 && patterns[p][k] != s[i]) {
          k = mps[p][k - 1] + 1;
        }
        if (k >= (I)patterns[p].size() - 1) {
          ++p;
          k = 0;
          if (p >= (I)patterns.size()) {
            found = true;
            break;
          }
        }
      }
    }

    cout << (found ? "Jest." : "Nie ma go.") << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

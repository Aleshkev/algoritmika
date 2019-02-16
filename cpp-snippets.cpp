#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

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

I f_lower_bound(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (f(mid)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

// Assumes first char is outside the alphabet.
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

struct hash_model {
  I p, q;
  vector<I> q_pow;
  hash_model(I p, I q, I max_n) : p(p), q(q) {
    q_pow.resize(max_n);
    q_pow[0] = 1;
    for (I i = 1; i < max_n; ++i) q_pow[i] = q_pow[i - 1] * q % p;
  }

  vector<I> make_hash(const string &s) {
    I n = s.size();
    vector<I> r(n);
    r[0] = s[0] - '`';
    for (I i = 1; i < n; ++i) r[i] = (r[i - 1] * q + s[i] - '`') % p;
    return r;
  }
  I get_range(const vector<I> &r, I a, I b) {
    if (a == 0) return r[b];
    return (p + r[b] - r[a - 1] * q_pow[b - a + 1] % p) % p;
  }
  I with_char(const string &s, const vector<I> &r, I i, char c) {
    return (p + r.back() + (c - s[i]) * q_pow[r.size() - i - 1] % p) % p;
  }
};

// Test the functions.
int main() {
  vector<I> v = {1, 1, 2, 2, 2, 3, 4, 10, 20, 1, 2, 3};
  set<I> w(v.begin(), v.end());
  cout << v << endl;

  // Should be equivalent.
  cout << f_lower_bound(0, v.size(), [&](I i) { return v[i] < 2; }) << endl;
  cout << lower_bound(v.begin(), v.end(), 2) - v.begin() << endl;

  system("pause");
  return 0;
}

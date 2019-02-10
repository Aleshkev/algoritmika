#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string pattern, s;
  cin >> pattern >> s;
  I m = pattern.size(), n = s.size();

  hash_model m1(1e9 + 7, 31, n), m2(1e9 + 13, 31, n);
  vector<I> pr1 = m1.make_hash(pattern), pr2 = m2.make_hash(pattern);
  vector<I> sr1 = m1.make_hash(s), sr2 = m2.make_hash(s);

  vector<I> correct1, correct2;
  for (I i = 0; i < m; ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      correct1.push_back(m1.with_char(pattern, pr1, i, c));
      correct2.push_back(m2.with_char(pattern, pr2, i, c));
    }
  }
  sort(correct1.begin(), correct1.end());
  sort(correct2.begin(), correct2.end());

  I z = 0;
  for (I i = 0; i + m - 1 < n; ++i) {
    if (binary_search(correct1.begin(), correct1.end(),
                      m1.get_range(sr1, i, i + m - 1)) &&
        binary_search(correct2.begin(), correct2.end(),
                      m2.get_range(sr2, i, i + m - 1))) {
      ++z;
    }
  }
  cout << z << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

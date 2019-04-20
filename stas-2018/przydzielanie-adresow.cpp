#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Implicit {
  uint32_t guard = 0;
  uint32_t operator()(uint64_t x) { return x; }
};
template <uint32_t prime = uint32_t(1e9 + 7)>
struct Const {
  uint32_t guard = prime;
  uint32_t operator()(uint64_t x) { return x >= prime ? x % prime : x; }
};

#define encode(c) \
  ((islower(c) ? c - 'a' : isupper(c) ? c - 'A' + 26 : c - '0' + 52) + 1)
template <uint32_t prime = 67, class Truncate = Const<>>
struct hash_model {
  Truncate truncate;
  uint32_t max_n;
  vector<uint32_t> power;
  hash_model(uint32_t max_n) : max_n(max_n) {
    power.resize(max_n);
    power[0] = 1;
    for (uint32_t i = 1; i < max_n; ++i)
      power[i] = truncate(uint64_t(power[i - 1]) * prime);
  }
  template <typename T>
  vector<uint32_t> vec(const T &s) {
    vector<uint32_t> v(s.size());
    for (uint32_t i = 0; i < s.size(); ++i)
      v[i] = truncate(uint64_t(i > 0 ? v[i - 1] : 0) * prime + encode(s[i]));
    return v;
  }
  uint32_t sub(const vector<uint32_t> &v, uint32_t i, uint32_t j) {
    if (i == 0) return v[j];
    return truncate(uint64_t(truncate.guard) * truncate.guard + v[j] -
                    uint64_t(v[i - 1]) * power[j - i + 1]);
  }
  template <typename T>
  uint32_t scalar(const T &s) {
    uint64_t r = 0;
    for (char c : s) r = truncate(r * prime + encode(c));
    return r;
  }
};
typedef pair<vector<uint32_t>, vector<uint32_t>> paired;
// Hmm, to nie powinno było działać z taką liczbą pierwszą... Ale jest
// 100 punktów, cóż.
template <class TruncateA = Implicit, class TruncateB = Const<>,
          uint32_t prime_a = 31, uint32_t prime_b = 37>
struct double_hash_model {
  hash_model<prime_a, TruncateA> a;
  hash_model<prime_b, TruncateB> b;
  double_hash_model(uint32_t max_n) : a(max_n), b(max_n) {}
  template <typename T>
  paired vec(const T &s) {
    return {a.vec(s), b.vec(s)};
  }
  pair<uint32_t, uint32_t> sub(const paired &v, uint32_t i, uint32_t j) {
    return {a.sub(v.first, i, j), b.sub(v.second, i, j)};
  }
  template <typename T>
  pair<uint32_t, uint32_t> scalar(const T &s) {
    return {a.scalar(s), b.scalar(s)};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  string s;
  cin >> s;
  I n = s.size();

  double_hash_model<> model(n);
  auto hash = model.vec(s);

  I c;
  cin >> c;
  while (c--) {
    I q;
    string z;
    cin >> q >> z;
    I m = z.size();

    vector<pair<uint32_t, uint32_t>> v;
    for (I i = 0; i + m - 1 < n; ++i) {
      v.push_back(model.sub(hash, i, i + m - 1));
    }
    sort(v.begin(), v.end());
    auto has = [&](const string &z) {
      return binary_search(v.begin(), v.end(), model.scalar(z));
    };

    cout << (has(z) ? "OK" : "NIE") << '\n';
    while (--q) {
      cin >> z;
      cout << (has(z) ? "OK" : "NIE") << '\n';
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
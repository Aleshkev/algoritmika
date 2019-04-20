#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

template <uint32_t prime = uint32_t(1e9 + 7)>
struct Const {
  uint32_t guard = prime;
  uint32_t operator()(uint64_t x) { return x >= prime ? x % prime : x; }
};
#define encode(c) (c - 'a' + 1)
template <uint32_t prime = 31, class Truncate = Const<>>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;
  string s;
  cin >> s;

  hash_model<> model(n);
  auto hash = model.vec(s);

  vector<I> seq = {0};
  for (I i = 1; seq.size() < n; ++i) {
    vector<I> u;
    for (I j = i; j > 0; j /= 2) u.push_back(j % 2);
    for (I j = u.size() - 1; j >= 0 && seq.size() < n; --j) seq.push_back(u[j]);
  }

  for (I k = 1; k < n; ++k) {
    auto zero = model.sub(hash, 0, k - 1),
         one = model.sub(hash, k, min(n - 1, 2 * k - 1));
    bool ok = true;
    for (I i = 2;; ++i) {
      I len = min(n - i * k, k);
      if (model.sub(hash, seq[i] * k, seq[i] * k + len - 1) !=
          model.sub(hash, i * k, i * k + len - 1)) {
        ok = false;
        break;
      }
      if (i * k + k >= n) break;
    }
    if (ok) {
      cout << (n + k - 1) / k << '\n';
      break;
    };
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
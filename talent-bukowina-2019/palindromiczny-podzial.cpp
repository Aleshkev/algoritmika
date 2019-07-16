#include <bits/stdc++.h>
using namespace std;
typedef int32_t I;

struct Implicit {
  uint32_t guard = 0;
  uint32_t operator()(uint64_t x) { return x; }
};

#define encode(c) (c - 'a' + 1)
template <uint32_t prime = 31, class Truncate = Implicit>
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
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  constexpr I max_n = 1e6;
  hash_model<> hash(max_n);

  I t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    I n = s.size();

    auto s_v = hash.vec(s);

    I i = 0, c = 0;
    for (;;) {
      I k = 1;
      while (hash.sub(s_v, i, i + k - 1) !=
             hash.sub(s_v, n - i - k, n - i - k + k - 1))
        ++k;

      c += 2;
      if (i + k > n - i - k) --c;

      i += k;
      if (i >= (n + 1) / 2) {
        break;
      }
    }

    cout << c << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

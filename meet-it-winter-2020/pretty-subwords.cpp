#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef intmax_t I;

typedef uint64_t u64;
typedef uint32_t u32;

template <u32 prime>
struct Const {
  u32 guard = prime;
  u32 operator()(u64 x) { return x >= prime ? x % prime : x; }
};
struct Implicit {
  u32 guard = 0;
  u32 operator()(uint64_t x) { return x; }
};

#define encode(c) (c - 'a' + 1)
template <u32 prime = 31, class Truncate = Const<(u32)1e9 + 7>>
struct hash_model {
  Truncate truncate;
  u32 max_n;
  vector<u32> power;
  hash_model(u32 max_n) : max_n(max_n) {
    power.resize(max_n);
    power[0] = 1;
    for (u32 i = 1; i < max_n; ++i)
      power[i] = truncate(u64(power[i - 1]) * prime);
  }
  template <typename T>
  vector<u32> vec(const T &s) {
    vector<u32> v(s.size());
    for (u32 i = 0; i < s.size(); ++i)
      v[i] = truncate(u64(i > 0 ? v[i - 1] : 0) * prime + encode(s[i]));
    return v;
  }
  u32 sub(const vector<u32> &v, u32 i, u32 j) {
    if (i == 0) return v[j];
    return truncate(u64(truncate.guard) * truncate.guard + v[j] -
                    u64(v[i - 1]) * power[j - i + 1]);
  }
};

I f_search(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (f(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}

typedef pair<vector<u32>, vector<u32>> paired;
template <class TruncateA = Implicit, class TruncateB = Const<(u32)1e9 + 7>,
          u32 prime_a = 31, u32 prime_b = 37>
struct double_hash_model {
  hash_model<prime_a, TruncateA> a;
  hash_model<prime_b, TruncateB> b;
  double_hash_model(u32 max_n) : a(max_n), b(max_n) {}
  template <typename T>
  paired vec(const T &s) {
    return {a.vec(s), b.vec(s)};
  }
  u64 sub(const paired &v, u32 i, u32 j) {
    return ((u64)a.sub(v.first, i, j) << 32) | b.sub(v.second, i, j);
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n;
  cin >> n;
  string s;
  cin >> s;

  double_hash_model<> model(s.size());
  auto v = model.vec(s);

  auto is_ok = [&](I k) {
    auto at = [&](I i) { return model.sub(v, i, i + k - 1); };

    gp_hash_table<u64, I> z;
    for (I i = k - 1; i + k <= n; ++i) {
      ++z[at(i)];
    }

    for (I i = 0; i + k < n; ++i) {
      if (i + k - 1 + k <= n) {
        auto p = at(i + k - 1);
        --z[p];
      }
      if (i - k >= 0) {
        ++z[at(i - k)];
      }

      auto it = z.find(at(i));
      if (it != z.end() && it->second > 0) return true;
    }

    return false;
  };

  cout << f_search(1, n / 2 + 1, is_ok) - 1 << "\n";

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

template <uint32_t prime>
struct Const {
  uint32_t guard = prime;
  uint32_t operator()(uint64_t x) { return x >= prime ? x % prime : x; }
};

template <uint32_t prime = 200003, class Truncate = Const<int32_t(1e9 + 7)>>
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
  vector<uint32_t> vec(const vector<I> &s) {
    vector<uint32_t> v;
    v.resize(s.size());
    if (s.empty()) return v;
    v[0] = s[0];
    for (uint32_t i = 1; i < s.size(); ++i)
      v[i] = truncate(uint64_t(v[i - 1]) * prime + s[i]);
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

  I n;
  cin >> n;
  vector<I> v_fd(n);
  for (I &i : v_fd) cin >> i;

  vector<I> v_bk = v_fd;
  reverse(v_bk.begin(), v_bk.end());

  hash_model<> model(v_fd.size());
  auto hash_fd = model.vec(v_fd), hash_bk = model.vec(v_bk);

  I b = 0;
  vector<I> r;
  for (I k = 1; k <= n; ++k) {
    vector<I> u(n / k);
    for (I i = 0; i < n / k; ++i) {
      u[i] = min(model.sub(hash_fd, i * k, (i + 1) * k - 1),
                 model.sub(hash_bk, n - ((i + 1) * k - 1) - 1, n - i * k - 1));
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    if (u.size() > b) {
      b = u.size();
      r.clear();
    }
    if (u.size() == b) {
      r.push_back(k);
    }
  }
  cout << b << ' ' << r.size() << '\n';
  for (I k : r) cout << k << ' ';
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
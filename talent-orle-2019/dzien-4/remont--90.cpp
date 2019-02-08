#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

I qpow(I base, I exp, I p) {
  I ans = 1;
  while (exp) {
    if (exp & 1) {
      ans = ans * base % p;
    }
    exp >>= 1;
    base = base * base % p;
  }
  return ans % p;
}
I inv(I x, I p) { return qpow(x, p - 2, p); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<vector<I>> tree(n);
  for (I i = 1; i < n; ++i) {
    I parent;
    cin >> parent;
    --parent;
    tree[parent].push_back(i);
  }

  const I p = 1e9 + 7;

  vector<I> sub(n);
  {
    function<void(I)> dfs = [&](I i) {
      sub[i] = 1;
      for (I j : tree[i]) {
        dfs(j);
        sub[i] = (sub[i] * (sub[j] + 1)) % p;
      }
    };
    dfs(0);
  }

  vector<I> sup(n);
  {
    function<void(I)> dfs = [&](I i) {
      for (I j : tree[i]) {
        sup[j] = (sub[i] * inv(sub[j] + 1, p) % p * sup[i] + 1) % p;
        dfs(j);
      }
    };
    sup[0] = 1;
    dfs(0);
  }

  for (I i = 0; i < n; ++i) {
    cout << sub[i] * sup[i] % p << ' ';
  }
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

#ifdef UNITEST
#define g getchar
#define p putchar
#else
#define g getchar_unlocked
#define p putchar_unlocked
#endif
inline bool iswhite(char c) { return c == ' ' || c == '\n'; }

struct fast_io {
  char eat_blank() {
    char c = g();
    while (iswhite(c)) c = g();
    return c;
  }
  template <typename T>
  typename enable_if<is_integral<T>::value, fast_io>::type operator>>(T &x) {
    x = 0;
    for (char c = eat_blank(); !iswhite(c); c = g()) x = 10 * x + c - '0';
    return *this;
  }
  template <typename T>
  typename enable_if<is_integral<T>::value, fast_io>::type operator<<(T x) {
    if (x == 0)
      p('0');
    else {
      char d[20];
      int32_t i = 0;
      for (; x > 0; x /= 10) d[i++] = '0' + x % 10;
      for (--i; i >= 0; --i) p(d[i]);
    }
    return *this;
  }
  fast_io &operator<<(char c) {
    p(c);
    return *this;
  }
} io;

int main() {
  I n;
  io >> n;

  vector<vector<I>> graph(n);
  for (I i = 0; i < n - 1; ++i) {
    I a, b;
    io >> a >> b;
    --a, --b;
    graph[a].push_back(b), graph[b].push_back(a);
  }

  vector<vector<I>> tree(n);
  {
    vector<bool> visited(n);
    vector<I> q = {0};
    visited[0] = true;
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        tree[i].push_back(j);
        q.push_back(j);
      }
    }
  }

  vector<I> u(n), v(n);  // u to wynik jeżeli rodzic się zapali, v jeżeli nie.
  function<void(I)> dfs = [&](I i) {
    if (tree[i].empty()) {
      u[i] = v[i] = 1;
      return;
    }

    for (I j : tree[i]) dfs(j);

    sort(tree[i].begin(), tree[i].end(),
         [&](I x, I y) { return v[x] - u[x] < v[y] - u[y]; });
    I sum_u = 0;
    for (I j : tree[i]) sum_u += u[j];

    u[i] = 1 + sum_u;
    u[i] = min(u[i], v[tree[i][0]] + sum_u - u[tree[i][0]]);

    v[i] = 1 + sum_u;
    if (tree[i].size() > 1)
      v[i] = min(v[i], (v[tree[i][0]] + v[tree[i][1]] +  //
                        sum_u - u[tree[i][0]] - u[tree[i][1]]));
  };
  dfs(0);

  io << v[0] << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

const I max_n = 1e6;
I next_i = 1, reachable = 1;

vector<vector<I>> children(max_n + 1);
vector<bool> dead(max_n + 1);

I add(I a) {
  I i = next_i++;
  children[a].push_back(i);
  if (dead[a])
    dead[i] = true;
  else
    ++reachable;
  return reachable;
}

I rem(I a, I b) {
  if (b < a) swap(a, b);  // If a < b, then a is the parent of b.

  if (!dead[b]) {
    vector<I> q = {b};
    dead[b] = true, --reachable;

    while (!q.empty()) {
      I i = q.back();
      q.pop_back();

      for (I j : children[i]) {
        if (dead[j]) continue;
        dead[j] = true, --reachable;

        q.push_back(j);
      }
    }
  }
  return reachable;
}

void UmyjRece() {}
int Dodaj(int v) { return add(v); }
int Usun(int v, int u) { return rem(v, u); }

// Ha ha, funkcja main "pojawia się w programie" i nic na to nie poradzicie.
#ifdef UNITEST
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  char o;
  while (cin >> o) {
    if (o == '+') {
      I a;
      cin >> a;
      cout << add(a) << endl;
    } else {
      I a, b;
      cin >> a >> b;
      cout << rem(a, b) << endl;
    }
  }

  cout.flush();
  system("pause");
  return 0;
}
#endif

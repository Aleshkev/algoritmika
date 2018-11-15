// Also known as Perfect Security from Codeforces.
// http://codeforces.com/contest/947/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;

const I depth = 30;

struct Node {
  Node *parent;
  Node *children[2];
  I population;
};

Node tree[7000000];
I last = 0;
Node *root = &tree[0];

void add(I number, I x = +1) {
  Node *i = root;
  for (I k = depth - 1; k >= 0; --k) {
    I b = ((number & (1 << k)) > 0);
    if (i->children[b] == nullptr) {
      tree[++last].parent = i;
      i->children[b] = &tree[last];
    }
    i = i->children[b];
  }
  i->population += x;
  for (I k = 1; k < depth; ++k) {
    i = i->parent;
    i->population =
        ((i->children[0] != nullptr ? i->children[0]->population : 0) +
         (i->children[1] != nullptr ? i->children[1]->population : 0));
  }
}
I decide(I number) {
  Node *i = root;

  I decided = 0;
  for (I k = depth - 1; k >= 0; --k) {
    I b = ((number & (1 << k)) > 0);
    if (i->children[b] != nullptr && i->children[b]->population > 0) {
      i = i->children[b];
      decided = 2 * decided + b;
    } else {
      i = i->children[!b];
      decided = 2 * decided + !b;
    }
  }
  return decided;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n;
  cin >> n;

  vector<I> key(n);
  for (I &i : key) cin >> i;

  for (I i = 0; i < n; ++i) {
    I a;
    cin >> a, add(a);
  }

  for (I i = 0; i < n; ++i) {
    I k = key[i];
    I x = decide(k);
    add(x, -1);
    cout << (k ^ x) << ' ';
  }
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

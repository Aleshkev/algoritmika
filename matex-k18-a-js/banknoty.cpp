#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

struct Note {
  I denomination, quantity, i;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I n;
  cin >> n;

  vector<Note> notes(n);
  for (Note &i : notes) cin >> i.denomination;
  for (Note &i : notes) cin >> i.quantity;
  for (I i = 0; i < n; ++i) notes[i].i = i;

  I k;
  cin >> k;

  vector<I> d(k + 1, inf);
  vector<vector<I>> c(k + 1, vector<I>(n));
  d[0] = 0;

  sort(notes.begin(), notes.end(),
       [&](Note a, Note b) { return a.denomination > b.denomination; });

  for (Note note : notes) {
    I value = note.denomination;
    for (I l = 0; l < note.quantity; ++l) {
      bool changed = false;
      for (I i = k - value; i >= 0; --i) {
        if (d[i] >= inf) continue;

        if (d[i] + 1 < d[i + value]) {
          changed = true;
          d[i + value] = d[i] + 1;
          c[i + value] = c[i];
          ++c[i + value][note.i];
        }
      }
      if (!changed) {
        break;
      }
    }
  }
  cout << d[k] << '\n';
  for (I x : c[k]) {
    cout << x << ' ';
  }
  cout << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

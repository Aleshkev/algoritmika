#include <bits/stdc++.h>

//      ░█                                    █░
//   ██████  ███▄ ▄███▓ ██▓▓█████  ██▀███   ▄████▄     ▄▄▄█████▓ ▒█████   ██▓███
//   ██████ ▓█████  ██ ▄█▀ ██▀███  ▓█████▄▄▄█████▓ ▒█████   █     █░ ██▓
// ▒██    ▒ ▓██▒▀█▀ ██▒▓██▒▓█   ▀ ▓██ ▒ ██▒▒██▀ ▀█     ▓  ██▒ ▓▒▒██▒  ██▒▓██░
// ██▒▒██    ▒ ▓█   ▀  ██▄█▒ ▓██ ▒ ██▒▓█   ▀▓  ██▒ ▓▒▒██▒  ██▒▓█░ █ ░█░▓██▒ ░
// ▓██▄   ▓██    ▓██░▒██▒▒███   ▓██ ░▄█ ▒▒▓█    ▄    ▒ ▓██░ ▒░▒██░  ██▒▓██░
// ██▓▒░ ▓██▄   ▒███   ▓███▄░ ▓██ ░▄█ ▒▒███  ▒ ▓██░ ▒░▒██░  ██▒▒█░ █ ░█ ▒██▒
//   ▒   ██▒▒██    ▒██ ░██░▒▓█  ▄ ▒██▀▀█▄  ▒▓▓▄ ▄██▒   ░ ▓██▓ ░ ▒██   ██░▒██▄█▓▒
//   ▒  ▒   ██▒▒▓█  ▄ ▓██ █▄ ▒██▀▀█▄  ▒▓█  ▄░ ▓██▓ ░ ▒██   ██░░█░ █ ░█ ░██░
// ▒██████▒▒▒██▒   ░██▒░██░░▒████▒░██▓ ▒██▒▒ ▓███▀ ░     ▒██▒ ░ ░ ████▓▒░▒██▒ ░
// ░▒██████▒▒░▒████▒▒██▒ █▄░██▓ ▒██▒░▒████▒ ▒██▒ ░ ░ ████▓▒░░░██▒██▓ ░██░ ▒ ▒▓▒
// ▒ ░░ ▒░   ░  ░░▓  ░░ ▒░ ░░ ▒▓ ░▒▓░░ ░▒ ▒  ░     ▒ ░░   ░ ▒░▒░▒░ ▒▓▒░ ░  ░▒
// ▒▓▒ ▒ ░░░ ▒░ ░▒ ▒▒ ▓▒░ ▒▓ ░▒▓░░░ ▒░ ░ ▒ ░░   ░ ▒░▒░▒░ ░ ▓░▒ ▒  ░▓ ░ ░▒  ░ ░░
// ░      ░ ▒ ░ ░ ░  ░  ░▒ ░ ▒░  ░  ▒          ░      ░ ▒ ▒░ ░▒ ░     ░ ░▒  ░ ░
// ░ ░  ░░ ░▒ ▒░  ░▒ ░ ▒░ ░ ░  ░   ░      ░ ▒ ▒░   ▒ ░ ░   ▒ ░ ░  ░  ░  ░      ░
// ▒ ░   ░     ░░   ░ ░             ░      ░ ░ ░ ▒  ░░       ░  ░  ░     ░   ░
// ░░ ░   ░░   ░    ░    ░      ░ ░ ░ ▒    ░   ░   ▒ ░
//       ░         ░    ░     ░  ░   ░     ░ ░                      ░ ░ ░     ░
//       ░░  ░      ░        ░  ░            ░ ░      ░     ░
//                                         ░
using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    o << *i;
    if (i != prev(v.end())) o << ", ";
  }
  o << "]";
  return o;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  vector<I> reverse;
  vector<I> s;

  I n;
  cin >> n;
  for (I i = 0; i < n; ++i) {
    cout << i << ": " << s << endl;
    char o;
    cin >> o;
    if (o == '+') {
      I x;
      cin >> x;
      s.push_back(x);
      reverse.push_back(inf);
    } else if (o == '-') {
      reverse.push_back(s.back());
      s.pop_back();
    } else if (o == '*') {
      I x;
      cin >> x;
      cout << s << endl;
      cout << reverse << endl;
      while (x--) {
        if (reverse.back() == inf) {
          s.pop_back();
        } else {
          s.push_back(reverse.back());
        }
        reverse.pop_back();
      }
      cout << reverse << endl;
    }
    cout << s.back() << '\n';
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}

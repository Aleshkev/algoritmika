#include <bits/stdc++.h>

using namespace std;

typedef int8_t i8;
typedef int32_t i32;
// typedef int32_t I;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    cout << *i;
    if (i != prev(v.end())) cout << ", ";
  }
  cout << "]";
  return o;
}

ostream &operator<<(ostream &o, const vector<i8> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    cout << i32(*i);
    if (i != prev(v.end())) cout << ", ";
  }
  cout << "]";
  return o;
}

const string alphabet = "ATCGABCD";
i8 normalize(char c) {
  return (find(alphabet.begin(), alphabet.end(), c) - alphabet.begin()) % 4;
}
char denormalize(i8 i) { return alphabet[i]; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<i32> n(2);
  vector<vector<i8>> normalized(2);
  vector<vector<vector<i32>>> prev_occurrence(2, vector<vector<i32>>(4));

  for (i8 k = 0; k < 2; ++k) {
    string s;
    cin >> s;
    n[k] = s.size();
    for (char c : s) normalized[k].push_back(normalize(c));

    for (i8 c = 0; c < 4; ++c) {
      prev_occurrence[k][c].resize(n[k]);
      prev_occurrence[k][c][0] = (normalized[k][0] == c ? 0 : -1);
      for (i32 i = 1; i < n[k]; ++i) {
        if (normalized[k][i] == c) {
          prev_occurrence[k][c][i] = i;
        } else {
          prev_occurrence[k][c][i] = prev_occurrence[k][c][i - 1];
        }
      }
    }

    // cout << normalized[k] << endl;
    // for (i32 c = 0; c < 4; ++c) {
    //   cout << c << ": " << prev_occurrence[k][c] << endl;
    // }
  }

  vector<i8> result;

  vector<vector<i32>> s = {{n[0]}, {n[1]}};

  i32 b0 = 0, b1 = 0;
  while (!s[0].empty()) {
    i32 e0 = s[0].back(), e1 = s[1].back();
    i32 p0 = -1, p1 = -1;
    for (i8 c = 0; c < 4; ++c) {
      if (e0 <= 0 || e1 <= 0) break;
      i32 l0 = prev_occurrence[0][c][e0 - 1],
          l1 = prev_occurrence[1][c][e1 - 1];
      if (l0 >= b0 && l1 >= b1) {
        p0 = l0, p1 = l1;
        break;
      }
    }
    if (p0 != -1) {
      s[0].push_back(p0), s[1].push_back(p1);
    } else {
      b0 = find(normalized[0].begin() + b0, normalized[0].end(),
                normalized[0][e0]) -
           normalized[0].begin() + 1;
      b1 = find(normalized[1].begin() + b1, normalized[1].end(),
                normalized[1][e1]) -
           normalized[1].begin() + 1;
      if (e0 < n[0]) result.push_back(normalized[0][e0]);
      s[0].pop_back(), s[1].pop_back();
    }
  }

  // cout << result << endl;
  for (i8 i : result) cout << denormalize(i);
  cout << '\n';

#ifdef __MINGW32__
  // cout.flush();
  // system("pause");
#endif
  return 0;
}

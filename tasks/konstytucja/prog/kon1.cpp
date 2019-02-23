#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

inline bool is_letter(char c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void make_lowercase(string &s) {
  for_each(s.begin(), s.end(), [](char &c) { c = tolower(c); });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  for (;;) {
    string line;
    getline(cin, line);
    if (line.empty()) break;

    string minimal, maximal;
    string minimal_lower, maximal_lower;
    for (I i = 0; i < line.size(); ++i) {
      if (!is_letter(line[i])) continue;

      string word;
      while (i < line.size() && is_letter(line[i])) {
        word += line[i];
        ++i;
      }
      --i;

      string word_lower = word;
      make_lowercase(word_lower);

      if (minimal.empty()) {
        minimal = maximal = word;
        minimal_lower = maximal_lower = word_lower;
        continue;
      }

      if (word_lower < minimal_lower) {
        minimal = word;
        minimal_lower = word_lower;
      }
      if (word_lower > maximal_lower) {
        maximal = word;
        maximal_lower = word_lower;
      }
    }

    cout << minimal << ' ' << maximal << '\n';
  }
  return 0;
}

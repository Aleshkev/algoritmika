#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

inline bool isletter(char c) { return islower(c) || isupper(c); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I q;
  cin >> q;

  vector<I> queries(q);
  for (I i = 0; i < q; ++i) cin >> queries[i];

  cin.ignore();
  string s;
  getline(cin, s);
  I n = s.size();

  I spaces = count(s.begin(), s.end(), ' ');

  I numbers = 0;
  for (I i = 0; i < n; ++i) {
    if (isdigit(s[i])) {
      while (i < n && isdigit(s[i])) ++i;
      ++numbers;
    }
  }

  I words = 0;
  I palindromes = 0;
  for (I i = 0; i < n; ++i) {
    if (isletter(s[i])) {
      string word;
      while (i < n && isletter(s[i])) {
        word.push_back(tolower(s[i]));
        ++i;
      }
      ++words;

      string rword = word;
      reverse(rword.begin(), rword.end());
      if (word == rword) ++palindromes;
    }
  }

  I sentences = 0;
  for (I i = 0; i < n; ++i) {
    if (s[i] != '.') {
      bool any_word = false;
      while (i < n && s[i] != '.') {
        if (isletter(s[i])) any_word = true;
        ++i;
      }
      if (i < n && any_word) ++sentences;
    }
  }

  // cout << "spaces: " << spaces << endl;
  // cout << "numbers: " << numbers << endl;
  // cout << "words: " << words << endl;
  // cout << "sentences: " << sentences << endl;
  // cout << "palindromes: " << palindromes << endl;

  for (I i : queries) {
    cout << vector<I>({spaces, numbers, words, sentences, palindromes})[i - 1]
         << ' ';
  }
  cout << endl;

#ifdef __MINGW32__
  cout.flush();
  system("pause");
#endif
  return 0;
}

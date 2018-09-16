#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

vector<I> presufix(const string &s) {
    vector<I> p(s.size());
    p[0] = -1;
    I k = -1;
    for(I i = 1; i < s.size(); ++i) {
        while(k >= 0 && s[k + 1] != s[i]) {
            k = p[k];
        }
        ++k;
        p[i] = k;
    }
    return p;
}
int main()
{
    string w, s;
    cin >> w >> s;

    string z = "#" + w + "$" + s;

    auto p = presufix(z);  // Szuka w wewnątrz s

    for(char c : z) cout << setw(2) << c << ' '; cout << '\n';
    for(I i : p) cout << setw(2) << i << ' '; cout << '\n';

    I spl = 0;
    while(spl < w.size()) {
        string pat;
        while(w[spl] != '*') {
            pat += w[spl];
            ++spl;
        }
        ++spl;

        cout << pat << '\n';
    }

    return 0;
}

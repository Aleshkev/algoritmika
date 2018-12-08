#include <bits/stdc++.h>

using namespace std;

typedef int I;

inline bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main()
{
    cout.sync_with_stdio(false);

    I n, k;
    cin >> n >> k;
    cin.ignore();

    I c = 0;

    for(I i = 0; i < n; ++i) {
        string a, b;
        getline(cin, a);
        getline(cin, b);

        a.erase(remove(a.begin(), a.end(), ' '), a.end());
        b.erase(remove(b.begin(), b.end(), ' '), b.end());

        I va = 0, vb = 0;
        for(I j = 0; j < a.size(); ++j) {
            va += is_vowel(a[j]);
        }
        for(I j = 0; j < b.size(); ++j) {
            vb += is_vowel(b[j]);
        }

        if(va != vb || a.size() < k || b.size() < k) {
            continue;
        }

        for(I j = 1; j <= k; ++j) {
            if(a[a.size() - j] != b[b.size() - j]) {
                goto next_i;
            }
        }

        ++c;

        next_i:;
    }

    cout << c << '\n';

    return 0;
}

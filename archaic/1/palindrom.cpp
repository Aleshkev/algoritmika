#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n; cin >> n;

    string s;
    for(I i = 0; i < n; ++i) {
        cin >> s;
        I m = s.size();

        bool ok = true;
        for(I j = 0; j < m / 2; ++j) {
            if(s[j] != s[m - j - 1]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "TAK" : "NIE") << '\n';
    }

    return 0;
}

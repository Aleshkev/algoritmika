#include <bits/stdc++.h>

using namespace std;

typedef int I;

const string digits = "0123456789ABCDEF";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    I n = s.size();

    reverse(s.begin(), s.end());
    if(n % 4 != 0) {
        for(I i = 0; i < 4 - n % 4; ++i) {
            s += '0';
        }
    }
    reverse(s.begin(), s.end());
    n = s.size();

    string result;

    for(I i = 0; i < n; i += 4) {
        result += digits[(s[i] == '1') * 8 + (s[i + 1] == '1') * 4 + (s[i + 2] == '1') * 2 + (s[i + 3] == '1')];
    }

    cout << result << '\n';

    cout.flush(); _Exit(0);

    return 0;
}

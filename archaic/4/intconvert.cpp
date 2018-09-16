#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I x, y;
    cin >> x >> y;

    string a;
    cin >> a;
    //reverse(a.begin(), a.end());

    I bi = 0;
    for(char c : a) {
        I d = ('0' <= c && c <= '9' ? c - '0' : c - 'A' + 10);
        bi = (bi * x) + d;
    }

    string b;
    while(bi > 0) {
        I d = bi % y;
        char c = (d < 10 ? '0' + d : 'A' + d - 10);
        b.push_back(c);
        bi /= y;
    }
    reverse(b.begin(), b.end());
    cout << b << '\n';

    return 0;
}

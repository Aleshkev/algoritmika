#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I c = 0;
    string s;
    I x;
    while(cin >> s >> x) {
        c += (s.size() % 2 == 0 ? -1 : 1) * x;
    }
    cout << c << '\n';

    return 0;
}

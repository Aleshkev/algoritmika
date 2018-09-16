#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(NULL);

    I s[4];
    for(I i = 0; i < 4; ++i) cin >> s[i];
    I x = accumulate(s, s + 4, 0) / 3;
    for(I i = 0; i < 4; ++i) cout << x - s[i] << ' ';
    cout << '\n';

    return 0;
}

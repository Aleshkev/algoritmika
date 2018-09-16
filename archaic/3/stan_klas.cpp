#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    I x = (s1 + s2 + s3 + s4) / 3;

    cout << (x - s1) << ' ' << (x - s2) << ' ' << (x - s3) << ' ' << (x - s4) << '\n';

    return 0;
}

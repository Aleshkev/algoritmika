#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);
    I n, m; cin >> n >> m;

    I c = 0;
    for(I i = 1; i <= n; ++i) {
        for(I j = 1; j <= m; ++j) {
            //cout << i << ", " << j << endl;
            c += (n - i + 1) * (m - j + 1) * i * j;
            c %= 9204927;
            //cout << c << endl;
        }
    }

    cout << c << '\n';

    return 0;
}

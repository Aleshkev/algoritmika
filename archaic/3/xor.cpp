#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    I q;
    cin >> q;

    for(I i = 0; i < q; ++i) {
        I n;
        cin >> n;

        I m = (n / 4) * 4;
        I c = 0;
        for(I j = m; j <= n; ++j) {
            c ^= j;
        }
        cout << c << '\n';
    }


    return 0;
}

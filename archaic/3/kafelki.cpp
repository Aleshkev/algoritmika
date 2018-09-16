#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n, m;
    cin >> n >> m;

    const I lim = 1000000;

    vector<I> ntiles(lim + 1);
    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;
        ++ntiles[x];
    }

    vector<I> ndivtiles(lim + 1);
    for(I i = 1; i <= lim; ++i) {
        if(ntiles[i] == 0) {
            continue;
        }
        for(I j = i; j <= lim; j += i) {
            ndivtiles[j] += ntiles[i];
        }
    }

    /*for(I i = 1; i <= 20; ++i) {
        cout << i << ": " << ndivtiles[i] << '\n';
    }*/

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        cout << ndivtiles[__gcd(a, b)] << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I mod = 1e6;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I k, n;
    cin >> k >> n;

    const I lim = 5000;
    I t[lim + 1] = {0};
    t[0] = 1;
    for(I i = 0; i <= lim; ++i) {
        for(I j = 1; i + j <= lim; ++j) {
            if(j == k) continue;
            t[i + j] += t[i];
            t[i + j] %= mod;
        }
    }

    //for(I i = 1; i <= 20; ++i) cout << setw(4) << i << ' '; cout << '\n';
    //for(I i = 1; i <= 20; ++i) cout << setw(4) << t[i] << ' '; cout << '\n';

    for(I i = 0; i < n; ++i) {
        I q;
        cin >> q;
        cout << t[q] << '\n';
    }

    return 0;
}

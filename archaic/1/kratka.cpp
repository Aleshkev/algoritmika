#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n; cin >> n;

    static I t[200000][4];
    for(I y = 0; y < 4; ++y) {
        for(I x = 0; x < n; ++x) {
            cin >> t[x][y];
        }
    }

    static I u[200000][8];
    const I k0 = 0, k1 = 1, k2 = 2, k3 = 3, k02 = 4, k13 = 5, k03 = 6, knil = 7;

    I *ct = t[0], *cu = u[0];

    cu[k0] = ct[0];
    cu[k1] = ct[1];
    cu[k2] = ct[2];
    cu[k3] = ct[3];
    cu[k02] = ct[0] + ct[2];
    cu[k13] = ct[1] + ct[3];
    cu[k03] = ct[0] + ct[3];
    cu[knil] = 0;

    for(I x = 1; x < n; ++x) {
        ct = t[x]; cu = u[x];
        I *lu = u[x - 1];

        cu[k0] = ct[0] + max({lu[knil], lu[k1], lu[k2], lu[k3], lu[k13]});
        cu[k1] = ct[1] + max({lu[knil], lu[k0], lu[k2], lu[k3], lu[k02], lu[k03]});
        cu[k2] = ct[2] + max({lu[knil], lu[k0], lu[k1], lu[k3], lu[k13], lu[k03]});
        cu[k3] = ct[3] + max({lu[knil], lu[k0], lu[k1], lu[k2], lu[k02]});
        cu[k02] = ct[0] + ct[2] + max({lu[knil], lu[k1], lu[k3], lu[k13]});
        cu[k13] = ct[1] + ct[3] + max({lu[knil], lu[k0], lu[k2], lu[k02]});
        cu[k03] = ct[0] + ct[3] + max({lu[knil], lu[k1], lu[k2]});
        cu[knil] = max({lu[knil], lu[k0], lu[k1], lu[k2], lu[k3], lu[k02], lu[k13], lu[k03]});
    }

    /*for(I y = 0; y < 7; ++y) {
        for(I x = 0; x < n; ++x) {
            cout << u[x][y] << " ";
        } cout << endl;
    }*/

    I max_c = 0;
    for(I i = 0; i < 8; ++i) max_c = max(max_c, u[n - 1][i]);

    cout << max_c << '\n';

    return 0;
}

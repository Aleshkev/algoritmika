#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    static I t[500000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    static I u[500000];
    u[0] = -1;
    for(I i = 1; i < n; ++i) {
        I k = i - 1;
        while(k != -1 && t[k] <= t[i]) {
            k = u[k];
        }
        u[i] = k;
    }

    for(I i = 0; i < n; ++i) {
        cout << (u[i] >= 0 ? u[i] + 1 : -1) << '\n';
    }

    return 0;
}

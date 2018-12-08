#include <iostream>
#include <algorithm>

using namespace std;

typedef long long unsigned U;

int main()
{
    cout.sync_with_stdio(false);

    U n;
    cin >> n;

    U c = 1;
    const U mod = 1e9 + 7;

    U *t = new U[n];
    for(U i = 0; i < n; ++i) {
        cin >> t[i];
    }

    sort(t, t + n);

    for(U i = 0; i < n; ++i) {
        c *= (t[i] - i);
        c %= mod;
    }

    cout << c << '\n';

    return 0;
}

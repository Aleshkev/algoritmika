#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I lim = 1e9 + 33;

I qpow(I x, I y) {
    if(y == 1) return x;
    I p = qpow(x, y / 2) % lim;
    return p % lim * p % lim * (y % 2 != 0 ? x : 1) % lim;
}

int main()
{
    cout.sync_with_stdio(false);

    I n;
    cin >> n;

    I ones = 0;
    for(I c = 1; c <= n; c <<= 1) {
        ++ones;
    }

    //I c = (1 << (n - ones)) * ((1 << ones) - 1);
    I c = qpow(2, n - ones) * (qpow(2, ones) - 1) % lim;

    cout << c << '\n';

    return 0;
}

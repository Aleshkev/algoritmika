#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef double F;

int main()
{
    cout.sync_with_stdio(false);

    I n; cin >> n;

    I x = sqrt(n);
    n -= x * x;
    I c = (x - 1) * (x - 1) * 2 + (x - 1) * 2;

    for(I i = 0; n > 0 && i < 2; ++i) {
        ++c; --n;
        I dif = min(n, x - 1);
        c += dif * 2; n -= dif;
    }

    cout << c << endl;

    return 0;
}

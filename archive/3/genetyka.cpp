#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

void f(I n, I i, I a, I b) {
    //cout << "f(" << n << ", " << i << ", " << a << ":" << b << ")\n";
    if(n == 1) {
        cout << a << '\n';
        return;
    }

    I k = n / 2;
    if(i <= k) {
        f(k, k - i + 1, a + n - k, b);
    } else {
        f(n - k, n - i + 1, a, b - k);
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I x, y;
    cin >> x >> y;

    f(x, y, 1, x);

    return 0;
}

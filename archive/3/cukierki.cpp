#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I n, k;

I qmul(I a, I b) {
    if(a == 1) return b;
    I c = b * (a % 2) + qmul(a / 2, b) * 2;
    if(c > 2 * n) {
        cout << "NIE\n";
        exit(0);
    }
    return c;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    qmul(k, k + 1);
    cout << "TAK\n";

    return 0;
}

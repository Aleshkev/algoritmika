#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n, h, g;
    cin >> n >> h >> g;

    I x = (g - 8 * h) / (2 * (n + 1));

    cout << x * n * x << '\n';

    return 0;
}

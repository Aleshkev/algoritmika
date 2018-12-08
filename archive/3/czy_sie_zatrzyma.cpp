#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    cout << ((n & (n - 1)) == 0 ? "TAK" : "NIE") << '\n';

    return 0;
}

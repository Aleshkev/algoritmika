#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    I p, k;
    cin >> p >> k;

    cout << k * 100 / (100 - p) << '\n';

    return 0;
}

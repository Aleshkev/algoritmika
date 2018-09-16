#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I a, b;
    cin >> a >> b;

    I c = a - b, d = a;
    I g = __gcd(c, d);

    cout << c / g << "/" << d / g << '\n';

    return 0;
}

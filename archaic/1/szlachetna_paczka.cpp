#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int I;

I lcm(I a, I b) {
    return a * b / __gcd(a, b);
}

int main()
{
    I b, e; cin >> b >> e; --b;
    I c, d; cin >> c >> d;
    char ch; cin >> ch;

    I cp = e / c - b / c;

    I g = lcm(c, d);
    I repeated = e / g - b / g;

    if(ch == 'J') {
        cout << cp << '\n';
    } else {
        cout << cp - repeated << '\n';
    }

    return 0;
}

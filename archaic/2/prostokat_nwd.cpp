#include <iostream>

using namespace std;

typedef unsigned I;

I gcd(I a, I b) {
    I c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    cout.sync_with_stdio(false);

    I w, h;
    cin >> w >> h;

    I c = 0;
    c += w + h - 1;

    for(I x = 1; x < w; ++x) {
        c += x;
        for(I y = x + 1; y < h; ++y) {
           c += gcd(x, y) * 2;
        }
    }

    cout << c << endl;

    return 0;
}

#include <iostream>

using namespace std;

typedef int I;
typedef double F;

int main()
{
    I n; cin >> n;

    F area = 0;

    F fx, fy; cin >> fx >> fy;
    F lx = fx, ly = fy;
    for(I i = 1; i < n; ++i) {
        F x, y; cin >> x >> y;

        area += (lx + x) * (ly - y);

        lx = x; ly = y;
    }
    area += (lx + fx) * (ly - fy);

    area /= 2.0;

    cout << area << '\n';

    return 0;
}

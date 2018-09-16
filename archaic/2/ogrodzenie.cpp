#include <cstdio>
//#include <iostream>
#include <algorithm>

using namespace std;

typedef int I;

void print_points(I lx, I ly, I x, I y) {
    I dx = x - lx, dy = y - ly;
    I g = __gcd(dx, dy);
    I ndx = dx / g, ndy = dy / g;
    if(g > 0) {
        for(I j = 0; j < g; ++j) {
            printf("%i %i\n", lx + ndx * j, ly + ndy * j);
            //cout << lx + ndx * j << ' ' << ly + ndy * j << '\n';
        }
    } else {
        for(I j = 0; j > g; --j) {
            printf("%i %i\n", lx + ndx * j, ly + ndy * j);
            //cout << lx + ndx * j << ' ' << ly + ndy * j << '\n';
        }
    }
}

int main()
{
    //cout.sync_with_stdio(false);

    I n; // cin >> n;
    scanf("%i", &n);

    I fx, fy; //cin >> fx >> fy;
    scanf("%i %i", &fx, &fy);
    I lx = fx, ly = fy;
    for(I i = 1; i < n; ++i) {
        I x, y; //cin >> x >> y;
        scanf("%i %i", &x, &y);
        print_points(lx, ly, x, y);
        lx = x; ly = y;
    }
    print_points(lx, ly, fx, fy);

    return 0;
}

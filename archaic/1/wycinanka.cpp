#include <iostream>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    I w, h; cin >> w >> h;

    static I t[50][50];
    for(I x = 0; x < w; ++x) {
        fill(t[x], t[x] + h, 0);
    }

    I n; cin >> n;
    for(I i = 0; i < n; ++i) {
        I x, y; cin >> x >> y; --x; --y;
        t[x][y] = 1;
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << (t[x][y] ? '#' : '.') << ' ';
        } cout << endl;
    }*/

    static I u[50][50];
    u[0][0] = t[0][0];
    for(I x = 1; x < w; ++x) {
        u[x][0] = u[x - 1][0] + t[x][0];
    }
    for(I y = 1; y < h; ++y) {
        u[0][y] = u[0][y - 1] + t[0][y];
    }
    for(I y = 1; y < h; ++y) {
        for(I x = 1; x < w; ++x) {
            u[x][y] = u[x - 1][y] + u[x][y - 1] - u[x - 1][y - 1] + t[x][y];
        }
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << u[x][y] << ' ';
        } cout << endl;
    }*/

    I max_e = 1;
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            if(t[x][y] != 0) continue;
            for(I e = max_e; e <= w - x && e <= h - y; ++e) {
                if(u[x + e - 1][y + e - 1] -
                   (x > 0 ? u[x - 1][y + e - 1] : 0) - (y > 0 ? u[x + e - 1][y - 1] : 0) +
                   (x > 0 && y > 0 ? u[x - 1][y - 1] : 0) == 0) {
                   max_e = max(max_e, e);
                }
            }
        }
    }
    cout << max_e * max_e << endl;

    return 0;
}

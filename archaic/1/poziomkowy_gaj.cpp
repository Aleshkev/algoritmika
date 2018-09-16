#include <iostream>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I h, w;
    cin >> h >> w;

    static I t[50][50];
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cin >> t[x][y];
        }
    }

    static I u[50][50];
    u[w - 1][0] = t[w - 1][0];
    for(I x = w - 2; x >= 0; --x) u[x][0] = u[x + 1][0] + t[x][0];
    for(I y = 1; y < h; ++y) u[w - 1][y] = u[w - 1][y - 1] + t[w - 1][y];
    for(I x = w - 2; x >= 0; --x) {
        for(I y = 1; y < h; ++y) {
            u[x][y] = max(u[x + 1][y], u[x][y - 1]) + t[x][y];
        }
    }

    cout << u[0][h - 1] << endl;

    return 0;
}

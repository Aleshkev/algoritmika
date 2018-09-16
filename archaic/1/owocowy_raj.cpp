#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I w, h, b;
    cin >> h >> w >> b;

    static I t[50][50];
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cin >> t[x][y];
        }
    }

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

    I max_c = 0;
    for(I y = 0; y < h - b + 1; ++y) {
        for(I x = 0; x < w - b + 1; ++x) {
            I ex = x + b - 1, ey = y + b - 1;
            I c = u[ex][ey];
            if(x > 0) c -= u[x - 1][ey];
            if(y > 0) c -= u[ex][y - 1];
            if(x > 0 && y > 0) c += u[x - 1][y - 1];
            max_c = max(max_c, c);
        }
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << u[x][y] << ' ';
        } cout << endl;
    }*/

    cout << max_c << '\n';

    return 0;
}

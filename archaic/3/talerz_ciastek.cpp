#include <bits/stdc++.h>

using namespace std;

typedef int I;
const I inf = 10000;

I h, w;
bool t[1000][1000];
I u[1000][1000];

int main()
{
    scanf("%i %i", &h, &w);

    char s[1001];
    for(I y = 0; y < h; ++y) {
        scanf("%s", s);
        for(I x = 0; x < w; ++x) {
            t[x][y] = (s[x] == '#');
        }
    }

    for(I x = 0; x < w; ++x) {
        u[x][0] = t[x][0];
    }
    for(I y = 0; y < h; ++y) {
        u[0][y] = t[0][y];
    }
    for(I x = 1; x < w; ++x) {
        for(I y = 0; y < h; ++y) {
            if(t[x][y]) {
                u[x][y] = min(min(u[x - 1][y], u[x][y - 1]), u[x - 1][y - 1]) + 1;
            } else {
                u[x][y] = 0;
            }
        }
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << setw(2) << t[x][y] << ' ';
        } cout << '\n';
    } cout << '\n';

    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << setw(2) << u[x][y] << ' ';
        } cout << '\n';
    } cout << '\n';*/

    for(I x = 0; x < w; ++x) {
        for(I y = 0; y < h; ++y) {
            if(u[x][y] <= 1) {
                continue;
            }
            I k = u[x][y];
            // Sprytna optymalizacja
            if((x < w - 1 && u[x + 1][y] == k + 1) ||
               (y < h - 1 && u[x][y + 1] == k + 1) ||
               (x < w - 1 && y < h - 1 && u[x + 1][y + 1] == k + 1)) {
                continue;
            }
            for(I tx = x - k + 1; tx <= x; ++tx) {
                for(I ty = y - k + 1; ty <= y; ++ty) {
                    u[tx][ty] = max(u[tx][ty], k);
                }
            }
        }
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << setw(2) << u[x][y] << ' ';
        } cout << '\n';
    } cout << '\n';*/

    I min_v = inf;
    for(I x = 0; x < w; ++x) {
        for(I y = 0; y < h; ++y) {
            if(u[x][y] != 0) {
                min_v = min(min_v, u[x][y]);
            }
        }
    }

    printf("%i\n", min_v);

    return 0;
}

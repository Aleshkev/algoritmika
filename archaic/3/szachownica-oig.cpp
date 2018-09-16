#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I h, w;
    cin >> h >> w;

    static bool t[1000][1000];
    for(I y = 0; y < h; ++y) {
        char s[1000 + 1];
        cin >> s;
        for(I x = 0; x < w; ++x) {
            t[x][y] = (s[x] == '#');
        }
    }

    static I u[1000][1000];
    for(I x = 0; x < w; ++x) {
        u[x][0] = 1;
    }
    for(I y = 1; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            u[x][y] = 1;
            if(t[x][y - 1] != t[x][y]) {
                u[x][y] += u[x][y - 1];
            }
        }
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) cout << setw(2) << u[x][y] << ' '; cout << '\n';
    } cout << '\n';*/

    I sum_c = 0;
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            I min_u = u[x][y];
            I c = u[x][y];
            for(I i = x - 1; i >= 0 && t[i][y] != t[i + 1][y]; --i) {
                c += min(u[i][y], min_u);
                min_u = min(min_u, u[i][y]);
            }
            sum_c += c;
            //cout << setw(2) << c << ' ';
        } //cout << '\n';
    }

    cout << sum_c << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I h, w;
    cin >> h >> w;

    vector<vector<bool>> master(w, vector<bool>(h));
    for(I y = 0; y < h; ++y) {
        char s[101];
        cin >> s;
        for(I x = 0; x < w; ++x) {
            master[x][y] = (s[x] == '#');
        }
    }

    I n;
    cin >> n;

    for(I q = 0; q < n; ++q) {
        I sh, sw;
        cin >> sh >> sw;
        vector<vector<bool>> s(sw, vector<bool>(sh));

        for(I sy = 0; sy < sh; ++sy) {
            char z[101];
            cin >> z;
            for(I sx = 0; sx < sw; ++sx) {
                s[sx][sy] = (z[sx] == '#');
            }
        }

        I startx = 0;
        for(;;) {
            bool x_ok = false;
            for(I sy = 0; sy < w; ++sy) {
                if(s[startx][sy]) {
                    x_ok = true;
                    break;
                }
            }
            if(x_ok) {
                break;
            }
            ++startx;
        }
        I starty = 0;
        for(;;) {
            bool y_ok = false;
            for(I sx = 0; sx < h; ++sx) {
                if(s[sx][starty]) {
                    y_ok = true;
                    break;
                }
            }
            if(y_ok) {
                break;
            }
            ++starty;
        }
        I endx =
    }


    return 0;
}

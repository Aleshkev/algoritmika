#include <bits/stdc++.h>

using namespace std;

typedef long int I;
const I inf = 1e9;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I h, w;
    cin >> h >> w;

    static I t[500][500];
    bool any_positive = false;
    I max_number = -inf;
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cin >> t[x][y];
            if(t[x][y] > 0) {
                any_positive = true;
            }
            max_number = max(max_number, t[x][y]);
        }
    }

    if(!any_positive) {
        cout << max_number << '\n';
    } else {

        static I u[500][500];
        for(I x = 0; x < w; ++x) {
            partial_sum(t[x], t[x] + h, u[x]);
        }

        I max_c = 0;
        for(I y1 = 0; y1 < h; ++y1) {
            for(I y2 = y1; y2 < h; ++y2) {
                I yy_c = 0;
                for(I x = 0; x < w; ++x) {
                    yy_c += (u[x][y2] - (y1 > 0 ? u[x][y1 - 1] : 0));
                    if(yy_c < 0) {
                        yy_c = 0;
                    }
                    max_c = max(max_c, yy_c);
                }
            }
        }

        cout << max_c << '\n';
    }

    return 0;
}

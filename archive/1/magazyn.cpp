#include <iostream>

using namespace std;

typedef long long int I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);

    I h, w; cin >> h >> w;

    static I t[2000][2000];
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            char c; cin >> c;
            if(c == '#') {
                t[x][y] = inf;
            } else {
                t[x][y] = 0;
            }
        }
    }

    for(I x = 0; x < w; ++x) {
        for(I y = 0; y < h; ++y) {
            if(t[x][y] == 0) {
                for(I i = y - 1; i >= 0; --i) {
                    if(t[x][i] <= y - i) {
                        break;
                    }
                    t[x][i] = y - i;
                }
                for(I i = y + 1; i < h; ++i) {
                    if(t[x][i] <= i - y) {
                        break;
                    }
                    t[x][i] = i - y;
                }
            }
        }
    }

    I min_c = inf;
    for(I y = 0; y < h; ++y) {
        I c = 0;
        for(I x = 0; x < w; ++x) {
            c += t[x][y];
        }
        min_c = min(min_c, c);
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << t[x][y] << " ";
        } cout << endl;
    }*/

    cout << min_c << endl;


    return 0;
}

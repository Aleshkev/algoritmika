#include <iostream>

using namespace std;

typedef short unsigned SU;
typedef long long unsigned U;
const U inf = 1e18;

int main()
{
    U w, h;
    cin >> h >> w;

    SU **t = new SU *[w];
    for(U x = 0; x < w; ++x) {
        t[x] = new SU[h];
    }

    for(U y = 0; y < h; ++y) {
        for(U x = 0; x < w; ++x) {
            cin >> t[x][y];
        }
    }

    U min_sig = inf;

    for(U x = 0; x < w; ++x) {
        U c = 0;

        for(U i = 0; i < x; ++i) {
            c += t[i][0];
        }
        for(U y = 0; y < h; ++y) {
            c += t[x][y];
        }
        for(U i = x + 1; i < w; ++i) {
            c += t[i][h - 1];
        }

        min_sig = min(min_sig, c);
    }

    cout << min_sig << endl;

    return 0;
}

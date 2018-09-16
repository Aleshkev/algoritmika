#include <iostream>
#include <string>

using namespace std;

typedef long long unsigned U;
typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    U n;
    cin >> n;

    I x = 0, y = 0;
    I minx = 0, miny = 0, maxx = 0, maxy = 0;

    for(U i = 0; i < n; ++i) {
        U c;
        string s;
        cin >> c >> s;

        I diffx = 0, diffy = 0;
        I diffminx = 0, diffminy = 0, diffmaxx = 0, diffmaxy = 0;

        for(U i = 0; i < s.size(); ++i) {
            if(s[i] == 'N') {
                --diffy;
            } else if(s[i] == 'E') {
                ++diffx;
            } else if(s[i] == 'S') {
                ++diffy;
            } else {
                --diffx;
            }
            diffminx = min(diffminx, diffx); diffminy = min(diffminy, diffy);
            diffmaxx = max(diffmaxx, diffx); diffmaxy = max(diffmaxy, diffy);
        }

        /*for(U i = 0; i < c; ++i) {
            minx = min(minx, x + diffminx); miny = min(miny, y + diffminy);
            maxx = max(maxx, x + diffmaxx); maxy = max(maxy, y + diffmaxy);
            x += diffx; y += diffy;
            minx = min(minx, x); miny = min(miny, y);
            maxx = max(maxx, x); maxy = max(maxy, y);
        }*/
        //cout << diffminx << " " << diffmaxx << ", " << diffminy << " " << diffmaxy << '\n';
        minx = min(minx, x + diffminx); miny = min(miny, y + diffminy);
        maxx = max(maxx, x + diffmaxx); maxy = max(maxy, y + diffmaxy);
        x += diffx * (c - 1); y += diffy * (c - 1);
        minx = min(minx, x + diffminx); miny = min(miny, y + diffminy);
        maxx = max(maxx, x + diffmaxx); maxy = max(maxy, y + diffmaxy);
        x += diffx; y += diffy;
        minx = min(minx, x); miny = min(miny, y);
        maxx = max(maxx, x); maxy = max(maxy, y);
    }

    //cout << maxy << " " << miny << "\n";

    U w = maxx - minx, h = maxy - miny;

    cout << h << ' ' << w << '\n';

    return 0;
}

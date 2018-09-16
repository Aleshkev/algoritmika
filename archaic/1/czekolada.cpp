#include <bits/stdc++.h>

using namespace std;

typedef int I;

I ar(I u[][100], I x1, I y1, I x2, I y2) {
    return (u[x2][y2] - (x1 > 0 ? u[x1 - 1][y2] : 0) - (y1 > 0 ? u[x2][y1 - 1] : 0) +
            (x1 > 0 && y1 > 0 ? u[x1 - 1][y1 - 1] : 0));
}

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(NULL);

    I w, h;
    scanf("%i %i", &w, &h);

    static I t[100][100];
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            scanf("%i", &t[x][y]);
        }
    }

    static I u[100][100];
    u[0][0] = t[0][0];
    for(I x = 1; x < w; ++x) u[x][0] = u[x - 1][0] + t[x][0];
    for(I y = 1; y < h; ++y) u[0][y] = u[0][y - 1] + t[0][y];
    for(I x = 1; x < w; ++x) {
        for(I y = 1; y < h; ++y) {
            u[x][y] = u[x - 1][y] + u[x][y - 1] - u[x - 1][y - 1] + t[x][y];
        }
    }

    /*for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << u[x][y] << " ";
        } cout << endl;
    }*/

    I c = 0;
    for(I y1 = 0; y1 < h; ++y1) {
        for(I x1 = 0; x1 < w; ++x1) {
            for(I x2 = x1; x2 < w; ++x2) {
                for(I y2 = y1; y2 < h; ++y2) {
                    if(x1 == x2 && y1 == y2) continue;

                    bool ok = false;

                    for(I i = x1; !ok && i <= x2 - 1; ++i) {
                        I lt = ar(u, x1, y1, i, y2), rt = ar(u, i + 1, y1, x2, y2);
                        if(lt == rt) ok = true;
                    }
                    for(I i = y1; !ok && i <= y2 - 1; ++i) {
                        I top = ar(u, x1, y1, x2, i), bot = ar(u, x1, i + 1, x2, y2);
                        if(top == bot) ok = true;
                    }

                    if(ok) {
                        ++c;
                    }
                }
            }
        }
    }

    printf("%i\n", c);

    return 0;
}

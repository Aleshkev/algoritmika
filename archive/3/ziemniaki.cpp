#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n;
    scanf("%i", &n);

    I h, w;
    bool t[300][300];
    char s[300 + 1];

    for(I i = 0; i < n; ++i) {
        scanf("%i %i", &h, &w);
        for(I y = 0; y < h; ++y) {
            scanf("%s", s);
            for(I x = 0; x < w; ++x) {
                t[x][y] = (s[x] != '.');
            }
        }

        bool ok = true;

        for(I x = 0; x < w; ++x) {
            for(I y = 0; y < h; ++y) {
                if(!t[x][y]) continue;

                if(x < w - 1 && y < h - 1 && t[x + 1][y] && t[x][y + 1] && t[x + 1][y + 1]) {
                    t[x][y] = t[x + 1][y] = t[x][y + 1] = t[x + 1][y + 1] = false;
                } else {
                    ok = false;
                    goto break_xy;
                }
            }
        }
        break_xy:;

        printf("%s\n", (ok ? "TAK" : "NIE"));

    }

    return 0;
}

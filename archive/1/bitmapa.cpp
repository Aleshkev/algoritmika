#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct P {
    I x, y;
    P(I x_, I y_) : x(x_), y(y_) {};
};

int main()
{
    I w, h;
    scanf("%i %i", &h, &w);

    static vector<P> s[200];
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            char c; scanf(" %c", &c);
            if(c == '1') s[0].push_back(P(x, y));
        }
    }

    static I t[200][200];
    for(I x = 0; x < w; ++x) {
        fill(t[x], t[x] + h, -1);
    }

    for(I l = 0; ; ++l) {
        if(s[l].empty()) break;

        for(I i = 0; i < s[l].size(); ++i) {
            t[s[l][i].x][s[l][i].y] = l;
        }

        for(I i = 0; i < s[l].size(); ++i) {
            I x = s[l][i].x, y = s[l][i].y;

            if(x > 0 && t[x - 1][y] == -1) s[l + 1].push_back(P(x - 1, y));
            if(y > 0 && t[x][y - 1] == -1) s[l + 1].push_back(P(x, y - 1));
            if(x < w - 1 && t[x + 1][y] == -1) s[l + 1].push_back(P(x + 1, y));
            if(y < h - 1 && t[x][y + 1] == -1) s[l + 1].push_back(P(x, y + 1));
        }
    }

    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            printf("%i ", t[x][y]);
        } printf("\n");
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I h, w;
    cin >> h >> w;

    static char t[1000][1000];
    for(I y = 0; y < h; ++y) {
        char line[1000 + 1];
        cin >> line;
        for(I x = 0; x < w; ++x) {
            t[x][y] = line[x];
        }
    }

    I n;
    cin >> n;
    char s[1000 + 1];
    cin >> s;

    static I nmatches[1000][1000];

    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w - n + 1; ++x) {
            if(t[x][y] == s[0]) {
                bool ok = true;
                for(I i = 0; i < n; ++i) {
                    if(t[x + i][y] != s[i]) {
                        ok = false;
                    }
                }
                if(ok) {
                    for(I i = 0; i < n; ++i) {
                        ++nmatches[x + i][y];
                    }
                }
            }
        }
    }
    for(I x = 0; x < w; ++x) {
        for(I y = 0; y < h - n + 1; ++y) {
            if(t[x][y] == s[0]) {
                bool ok = true;
                for(I i = 0; i < n; ++i) {
                    if(t[x][y + i] != s[i]) {
                        ok = false;
                    }
                }
                if(ok) {
                    for(I i = 0; i < n; ++i) {
                        ++nmatches[x][y + i];
                    }
                }
            }
        }
    }

    I c = 0;

    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            if(nmatches[x][y] >= 2) {
                ++c;
            }
        }
    }

    cout << c << '\n';

    return 0;
}

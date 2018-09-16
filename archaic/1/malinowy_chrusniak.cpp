#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I h, w; cin >> h >> w;

    static I t[50][50];
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cin >> t[x][y];
        }
    }

    static I u[50][50];
    u[w - 1][h - 1] = t[w - 1][h - 1];
    for(I x = w - 2; x >= 0; --x) {
        u[x][h - 1] = u[x + 1][h - 1] + t[x][h - 1];
    }
    for(I y = h - 2; y >= 0; --y) {
        u[w - 1][y] = u[w - 1][y + 1] + t[w - 1][y];
    }
    for(I y = h - 2; y >= 0; --y) {
        for(I x = w - 2; x >= 0; --x) {
            u[x][y] = max(u[x + 1][y], u[x][y + 1]) + t[x][y];
        }
    }

    vector<pair<I, I> > v;
    for(I x = 0, y = 0; x != w - 1 || y != h - 1; ) {
        v.push_back(make_pair(x, y));
        if(y == h - 1 || (x < w - 1 && u[x + 1][y] > u[x][y + 1])) ++x;
        else ++y;
    }
    v.push_back(make_pair(w - 1, h - 1));

    cout << u[0][0] << '\n';
    for(I i = v.size() - 1; i >= 0; --i) {
        cout << v[i].second + 1 << ' ' << v[i].first + 1 << '\n';
    }

    return 0;
}

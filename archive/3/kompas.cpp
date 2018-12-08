#include <bits/stdc++.h>

using namespace std;

typedef long long int I;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I w, h, n;
    cin >> h >> w >> n;

    string path;
    cin >> path;

    vector<vector<I> > collected(w, vector<I>(h));

    I x = 0, y = 0;
    collected[0][0] = 1;
    I seq = 1;

    for(I i = 0; i < n; ++i) {
        if(path[i] == 'N') {
            --y;
        } else if(path[i] == 'S') {
            ++y;
        } else if(path[i] == 'E') {
            ++x;
        } else if(path[i] == 'W') {
            --x;
        }
        if(collected[x][y] == 0) {
            ++seq;
            collected[x][y] = seq;
        }
    }

    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cout << collected[x][y] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

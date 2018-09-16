#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    string s; cin >> s;
    I r; cin >> r;

    string z;
    for(I i = 0; i < r; ++i) {
        z += s;
    }

    static char t[5001][5001];

    I n = z.size() * 2;

    for(I i = 0; i < z.size(); ++i) {
        for(I x = i, y = i; x < n - i; ++x) t[y][x] = z[i];
        for(I x = i, y = i; y < n - i; ++y) t[y][x] = z[i];
        for(I x = n - i - 1, y = i; y < n - i; ++y) t[y][x] = z[i];
        for(I x = i, y = n - i - 1; x < n - i; ++x) t[y][x] = z[i];
    }

    for(I y = 0; y < n; ++y) {
        t[y][n] = '\0';
        cout << t[y] << '\n';
    }



    return 0;
}

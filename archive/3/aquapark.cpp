#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, m;
    cin >> n >> m;

    vector<vector<I> > values(2 * n, vector<I>(2 * n));

    for(I y = 0; y < n; ++y) {
        for(I x = 0; x < n; ++x) {
            I val;
            cin >> val;
            values[x - y + n][x + y + 1] = val;
        }
    }

    for(I y = 0; y < 2 * n; ++y) {
        for(I x = 0; x < 2 * n; ++x) {
            if(values[x][y] > 0) {
                cout << values[x][y];
            } else {
                cout << '.';
            }
            cout << ' ';
        }
        cout << endl;
    }

    vector<vector<I> > prefixes(2 * n, vector<I>(2 * n));

    for(I y = 1; y < 2 * n; ++y) {
        for(I x = 1; x < 2 * n; ++x) {
            prefixes[x][y] = prefixes[x - 1][y] + prefixes[x][y - 1] - prefixes[x - 1][y - 1] + values[x][y];
        }
    }

    for(I i = 0; i < m; ++i) {
        I x, y, k;
        cin >> y >> x >> k;
        --x; --y;

        I rx = x + k;
        I lx = x - k;

        I ra = min(rx - y + n, 2 * n - 1), rb = min(rx + y + 1, 2 * n - 1);
        I la = max(lx - y + n, (I)1), lb = max(lx + y + 1, (I)1);

        cout << prefixes[ra][rb] - prefixes[ra][lb - 1] - prefixes[la - 1][rb] + prefixes[la - 1][lb - 1] << '\n';
    }

    return 0;
}

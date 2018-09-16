#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I total_r, total_g, total_b;
    cin >> total_r >> total_g >> total_b;

    I n;
    cin >> n;

    cout << n << endl;

    static I r[100], g[100], b[100];
    for(I i = 0; i < n; ++i) {
        cin >> r[i] >> g[i] >> b[i];

        if(r[i] > total_r || g[i] > total_g || b[i] > total_b) {
            --i; --n;  // Ignore.
        }
    }

    static I c[101][101][101];
    for(I i = 0; i < n; ++i) {
        for(I x = total_r; x >= r[i]; --x) {
            for(I y = total_g; y >= g[i]; --y) {
                for(I z = total_b; z >= b[i]; --z) {
                    c[x][y][z] = max(c[x][y][z], c[x - r[i]][y - g[i]][z - b[i]] + 1);
                }
            }
        }
    }
    cout << c[total_r][total_g][total_b] << '\n';


    return 0;
}

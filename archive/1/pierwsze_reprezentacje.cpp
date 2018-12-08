#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    cout.sync_with_stdio(false);
    I n, k; cin >> n >> k;

    static I t[3001][21];
    vector<I> p;
    for(I i = 1; i <= n; ++i) t[i][1] = 1;
    t[1][1] = 0; t[2][1] = 1;
    for(I i = 1; i <= n; ++i) {
        if(t[i][1] == 0) continue;
        p.push_back(i);
        for(I j = i * 2; j <= n; j += i) {
            t[j][1] = 0;
        }
    }

    /*for(I i = 1; i <= n; ++i) {
        if(t[i][1]) { cout << i << " "; };
    } cout << endl;*/

    for(I i = 2; i <= k; ++i) {
        for(I j = 2; j <= n; ++j) {
            for(I l = distance(p.begin(), upper_bound(p.begin(), p.end(), (i == 2 ? j : j - 1))); l < p.size() && j + l <= n; ++l) {
                t[j + p[l]][i] += t[j][i - 1];
            }
        }
    }

    /*for(I i = 1; i <= k; ++i) {
        cout << i << ":: ";
        for(I j = 1; j <= n; ++j) {
            cout << t[j][i] << " ";
        } cout << endl;
    }*/

    cout << t[n][k] << endl;

    return 0;
}

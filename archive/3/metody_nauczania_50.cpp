#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, k;
    cin >> n >> k;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        t[i] = i * 2;
        //cin >> t[i];
    }
    sort(t.begin(), t.end());

    vector<map<I, I>> u(3);

    for(I i = 0; i < n; ++i) {
        ++u[0][t[i]];
    }

    for(I j = 1; j < 3; ++j) {
        for(auto it = u[j - 1].rbegin(); it != u[j - 1].rend(); ++it) {
            //cout << "'" << it->first << " " << it->second << '\n';
            for(I i = 0;  i < n; ++i) {
                u[j][it->first + t[i]] += it->second;
            }
        }
    }

    /*for(I i = 0; i < 3; ++i) {
        cout << i << ": ";
        for(II j : u[i]) {
            for(I l = 0; l < j.second; ++l) {
                cout << j.first << ' ';
            }
        } cout << '\n';
    }*/

    I c = 0;
    for(II p : u[2]) {
        c += p.second;
        if(c >= k) {
            cout << p.first << '\n';
            break;
        }
    }

    return 0;
}

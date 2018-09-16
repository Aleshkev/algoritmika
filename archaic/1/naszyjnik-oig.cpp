#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I n, m;
    cin >> n >> m;

    static I t[100000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for(I i = 0; i < m; ++i) {
        I q;
        cin >> q;

        I c = 0;

        map<I, I> cols;
        I uniq_cols = 0;

        I beg = 0, en = -1;
        while(uniq_cols <= q - 1) {
            ++en;
            ++cols[t[en]];
            uniq_cols += cols[t[en]] == 1;
        }
        ++en;

        c += en - beg;

        cout << beg << ":" << en << "(" << uniq_cols << ")" << endl;

        for(beg = 1; beg < n; ++beg) {
            --cols[t[beg - 1]];
            uniq_cols -= cols[t[beg - 1]] == 0;
            while(en < n && uniq_cols <= q - 1) {
                ++en;
                ++cols[t[en]];
                uniq_cols += cols[t[en]] == 1;
            }
            cout << beg << ":" << en << " (" << uniq_cols << ")" << endl;
            c += en - beg;
        }

        cout << c << '\n';
    }


    return 0;
}

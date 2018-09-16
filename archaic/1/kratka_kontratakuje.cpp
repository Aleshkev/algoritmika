#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

string binr(I n, I p = 8) {
    string s;
    for(I i = p - 1; i >= 0; --i) {
        s += ((n & (1 << i)) ? '1' : '0');
    }
    return s;
}

int main()
{
    I n; cin >> n;

    static vector<I> m[20];
    m[0] = {0, 1};
    for(I i = 0; i < n - 1; ++i) {
        for(I j = 0; j < m[i].size(); ++j) {
            m[i + 1].push_back(m[i][j] << 1);
            if((m[i][j] & 1) == 0) {
                m[i + 1].push_back((m[i][j] << 1) + 1);
            }
        }
    }

    for(I i = 0; i < n; ++i) {
        cout << i + 1 << ": ";
        for(I j = 0; j < m[i].size(); ++j) {
            cout << binr(m[i][j], i + 1) << ' ';
        } cout << endl;
    }

    return 0;
}

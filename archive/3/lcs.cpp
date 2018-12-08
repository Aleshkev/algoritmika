#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    static I t[5000 + 1][5000 + 1];

    for(I x = 0; x <= a.size(); ++x) {
        t[x][0] = 0;
    }
    for(I y = 0; y <= b.size(); ++y) {
        t[0][y] = 0;
    }

    for(I x = 1; x <= a.size(); ++x) {
        for(I y = 1; y <= b.size(); ++y) {
            if(a[x - 1] == b[y - 1]) {
                t[x][y] = t[x - 1][y - 1] + 1;
            } else {
                t[x][y] = max(t[x - 1][y], t[x][y - 1]);
            }
        }
    }

    /*for(I y = 0; y <= b.size(); ++y) {
        for(I x = 0; x <= a.size(); ++x) {
            cout << t[x][y] << ' ';
        } cout << '\n';
    }*/

    I n = t[a.size()][b.size()];
    string s;
    s.resize(n);
    I i = n - 1, cx = a.size(), cy = b.size();
    while(cx >= 0 && cy >= 0) {
        if(t[cx][cy] == t[cx - 1][cy]) {
            --cx;
        } else if(t[cx][cy] == t[cx][cy - 1]) {
            --cy;
        } else {
            s[i] = a[cx - 1]; --i;
            --cx; --cy;
        }
    }

    cout << n << '\n' << s << '\n';

    return 0;
}

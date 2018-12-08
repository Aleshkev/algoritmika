#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n;
    cin >> n;

    string s;//(n, '1');
    cin >> s;
    //n = s.size();
    //cout << s << ' ' << n << '\n';

    /*I k = 0;

    for(I i = 0; i < n; ++i) {
        k <<= 1;
        k += s[i] - '0';
    }
    cout << k << '\n';*/

    static I t[2][1000000 + 10];
    t[0][0] = t[1][0] = 0;
    for(I i = 0; i < n; ++i) {
        t[0][i + 1] = t[0][i];
        t[1][i + 1] = t[1][i];
        t[i % 2][i + 1] += s[i] - '0';
    }

    /*for(I i = 0; i < n; ++i) cout << s[i] << ' '; cout << '\n';
    for(I i = 0; i < n; ++i) cout << t[0][i + 1] << ' '; cout << '\n';
    for(I i = 0; i < n; ++i) cout << t[1][i + 1] << ' '; cout << '\n';*/

    static I _u[5] = {0};
    I *u = _u + 2;
    ++u[0];

    I c = 0, c1 = 0;
    for(I i = 1; i <= n; ++i) {
        /*for(I j = 0; j < i; ++j) {
            if((t[0][i] - t[1][i] - (t[0][j] - t[1][j]) % 3) % 3 == 0) {
                ++c;
                //cout << "i = " << i << ", j = " << j << '\n';
            }
        }*/
        I x = (t[0][i] - t[1][i]) % 3;
        I a = (x - 3) % 3, b = (x + 3) % 3;
        //cout << x << ": " << a << " " << b << '\n';
        c += u[a];
        if(a != b) c += u[b];
        ++u[x];
        /*for(I j = 0; j < i; ++j) {
            I y = (t[0][j] - t[1][j]) % 3;
            if(a == y || b == y) {
                ++c1;
            }
        }*/
        //cout << i << ": " << c << '\n';
    }
    cout << c << '\n';


    return 0;
}

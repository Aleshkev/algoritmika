#include <bits/stdc++.h>

using namespace std;

typedef int I;

char s[100001];
I t[100000][26];

int main()
{
    I n, m;
    scanf("%i %i %s", &n, &m, s);

    ++t[0][s[0] - 'a'];
    for(I i = 1; i < n; ++i) {
        copy(t[i - 1], t[i - 1] + 'z' - 'a' + 1, t[i]);
        ++t[i][s[i] - 'a'];
    }

    /*for(char c = 'a'; c <= 'z'; ++c) {
        cout << c << ": ";
        for(I i = 0; i < n; ++i) {
            cout << t[i][c] << ' ';
        } cout << endl;
    }*/

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        --a; --a; --b;

        I r = 0;
        for(char c = 'a'; c <= 'z'; ++c) {
            if(t[b][c - 'a'] - (a >= 0 ? t[a][c - 'a'] : 0) > 0) {
                ++r;
            }
        }

        printf("%i\n", r);
    }

    return 0;
}

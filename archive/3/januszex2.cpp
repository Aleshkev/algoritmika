#include <bits/stdc++.h>

using namespace std;

typedef int I;
const I inf = I(1e9);

const char JANUSZEX[] = "januszex";
const I JANUSZEX_LEN = sizeof(JANUSZEX);

int main()
{
    I n, m;
    scanf("%i %i", &n, &m);

    static char t[200000];
    static I u[200000][20];

    scanf("%s", t);

    for(I i = 0; i < n; ++i) {
        I needed_char_i = 0;
        I j;
        for(j = i; j < n; ++j) {
            if(t[j] == JANUSZEX[needed_char_i]) {
                ++needed_char_i;
                if(needed_char_i == JANUSZEX_LEN - 1) {
                    break;
                }
            }
        }

        u[i][0] = (j < n ? j : inf);
    }

    for(I k = 1; k <= 18; ++k) {
        for(I i = 0; i < n; ++i) {
            I last = u[i][k - 1];

            if(last >= inf || u[last][k - 1] >= inf) {
                u[i][k] = inf;
                continue;
            }

            u[i][k] = u[last][k - 1];
        }
    }

    /*for(I i = 0; i < n; ++i) {
        cerr << setw(2) << (i != inf ? i : -1) << ' ';
    } cerr << '\n';
    for(I i = 0; i < n; ++i) {
        cerr << setw(2) << t[i] << ' ';
    } cerr << '\n';
    for(I i = 0; i < 3; ++i) {
        for(I j = 0; j < n; ++j) {
            cerr << setw(2) << (u[j][i] != inf ? u[j][i] : -1) << ' ';
        } cerr << '\n';
    }*/

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        --a; --b;

        I c = 0;

        for(;;) {
            I x = upper_bound(u[a], u[a] + 20, b) - u[a] - 1;
            if(x < 0) break;
            c += (1 << x);
            a = u[a][x];
        }

        printf("%i\n", c);
    }

    return 0;
}

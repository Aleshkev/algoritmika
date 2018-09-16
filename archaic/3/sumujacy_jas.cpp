#include <bits/stdc++.h>

using namespace std;

typedef short unsigned U;
typedef int I;

int main()
{
    I n;
    scanf("%i", &n);

    const I rcomma = 250;
    static I result[400];

    for(I i = 0; i < n; ++i) {
        char s[250];
        scanf(" %s", s);
        I sn = strlen(s);

        I scomma = sn;
        for(I i = 0; i < sn; ++i) {
            if(s[i] == ',') {
                scomma = i;
                break;
            }
        }

        if(s[0] != '-') {
            I m = (s[0] == '+' ? 1 : 0);
            for(I x = 0 + m, y = rcomma - scomma + m; x < sn; ++x, ++y) {
                if(s[x] == ',') {
                    --y; continue;
                }
                result[y] += s[x] - '0';
            }
        } else {
            for(I x = 1, y = rcomma - scomma + 1; x < sn; ++x, ++y) {
                /*if(s[x] == ',') {
                    --y; continue;
                }*/
                result[y] -= s[x] - '0';
            }
        }

        for(I i = 400 - 1; i > 0; --i) {
            if(result[i] > 0) {
                result[i - 1] += result[i] / 10;
                result[i] %= 10;
            } else if(result[i] < 0) {
                result[i - 1] += (result[i] - 9) / 10;
                result[i] = 10 - (-result[i]) % 10;
            }
        }


        for(I i = rcomma - 10; i < rcomma; ++i) {
            cout << result[i] << ' ';
        } cout << ',';
        for(I i = rcomma; i < rcomma + 10; ++i) {
            cout << result[i] << ' ';
        } cout << endl;
    }


    return 0;
}

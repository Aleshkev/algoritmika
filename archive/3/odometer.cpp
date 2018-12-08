#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    ios_base::sync_with_stdio(false);

    //ifstream cin("odometer.in");
    //ofstream cout("odometer.out");

    I a, b;
    cin >> a >> b;

    I r = 0;

    for(I len = 3; len <= 17; ++len) {
        for(I y_i = 0; y_i < len; ++y_i) {
            for(I y = 0; y < 10; ++y) {
                for(I x = 0; x < 10; ++x) {
                    if(x == y || (y_i == 0 && y == 0) || (y_i != 0 && x == 0)) {
                        continue;
                    }
                    I c = 0;
                    for(I i = 0; i < len; ++i) {
                        c = c * 10 + (i == y_i ? y : x);
                    }

                    if(a <= c && c <= b) {
                        ++r;
                    }
                }
            }
        }
    }

    cout << r << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef long long unsigned U;

int main()
{
    cout.sync_with_stdio(false);

    U n;
    cin >> n;

    static U t[1000001] = {0};

    for(U i = 0; i < n; ++i) {
        U x;
        cin >> x;

        U c = 0;
        U f = 0;
        for(U k = 0; k < 32; ++k) {
            U mask = (1 << k);
            bool this_bit = ((x & mask) != 0);
            bool that_bit = ((x & (mask << 1)) != 0);
            if(this_bit == that_bit) {
                c += (this_bit << f);
                ++k; ++f;
            }
        }

        ++t[c];
    }

    cout << distance(t, max_element(t, t + 1000001)) << '\n';

    return 0;
}

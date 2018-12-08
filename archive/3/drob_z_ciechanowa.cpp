#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    const I n = 20;
    I s = 0;
    for(I x = 0; x < (1 << n); ++x) {
        I b = 0;

        for(I i = 0; i < n; ++i) {
            if(x & (1 << i)) {
                b |= (1 << ((i - 1 + n) % n));
            } else {
                b |= (1 << ((i + 1) % n));
            }
        }

        s += n - __builtin_popcount(b);
        //cout << bitset<n>(b) << ' ' << n - __builtin_popcount(b) << '\n';
    }

    cout << s << '\n';
    cout << s / (1 << n) << '\n';


    return 0;
}

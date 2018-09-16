#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    cin >> n;

    for(I i = 0; i < n; ++i) {
        I p, q;
        cin >> p >> q;

        I lo = 0, hi = (I)2e6;
        while(lo < hi) {
            I x = (lo + hi) / 2;

            I val = x * x * x + p * x;

            if(q <= val) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }

        I val = lo * lo * lo + p * lo;

        if(val == q) {
            cout << lo << '\n';
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}

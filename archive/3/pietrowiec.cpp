#include <bits/stdc++.h>

using namespace std;

typedef long int I;


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;
        if(x != 0) {
            t[i] /= x;
        } else {
            t[i] = (I)1e10;
        }
    }

    I seg = *min_element(t.begin(), t.end()) + 1;

    I l = 0;
    for(I b = 1; b <= seg; b <<= 1) ++l; --l;

    cout << l << '\n';

    return 0;
}

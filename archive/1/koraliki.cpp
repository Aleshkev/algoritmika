#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I n;
    cin >> n;

    static I t[100000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    I min_l = inf;

    for(I i = 0; i < n; ++i) {
        for(I j = min(i + min_l, n - 1); j > i; --j) {
            if(t[j] == t[i]) min_l = j - i;
        }
    }

    cout << min_l - 1 << endl;

    return 0;
}

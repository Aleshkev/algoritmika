#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

I n;
I t[1000000];

I lowb(I val) {
    I lo = 0, hi = n - 1;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(t[mid] >= val) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main()
{
    cin >> n;

    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    I m;
    cin >> m;

    for(I i = 0; i < m; ++i) {
        I val;
        cin >> val;
        I j = lowb(val);
        if(t[j] == val) cout << j + 1 << '\n';
        else cout << "Kup pudelko!\n";
    }

    return 0;
}

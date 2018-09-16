#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n, k;
    cin >> n >> k;

    static I t[1000010];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t, t + n);

    static I u[1000010];
    partial_sum(t, t + n, u);

    I c = 0;
    for(I i = 1; i < n; ++i) {
        I j = upper_bound(t, t + n, t[i] - k - 1) - t;
        c += k * (i - j);

        c += (j * t[i]) - u[j - 1];
    }

    cout << c << '\n';

    return 0;
}

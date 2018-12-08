#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);

    I n; cin >> n;
    I m = 2 * n;

    static I t[2000000];
    for(I i = 0; i < m; ++i) {
        cin >> t[i];
    }
    sort(t, t + m, greater<I>());

    static I u[2000000], v[2000000];
    partial_sum(t, t + m, u);

    v[m - 1] = t[m - 1]; v[m - 2] = t[m - 2];
    for(I i = m - 3; i >= 0; --i) {
        v[i] = v[i + 2] + t[i];
    }

    I min_a = inf;
    for(I i = 1; i <= n; ++i) {
        I h = t[0] + t[i];
        I w = u[i - 1] + v[m - (n - i) * 2];

        min_a = min(min_a, h * w);
    }

    cout << min_a << endl;


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

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

    if(n <= 20) {
        I c = inf;
        for(I m = 0; m < (1 << n); ++m) {
            I s = t[n - 1];
            for(I i = n - 2, d = 1; i >= 0; --i, ++d) {
                if(m & (1 << i)) {
                    s += t[i];
                    d = 0;
                } else {
                    s += d;
                }
            }
            c = min(c, s);
        }
        cout << c << '\n';
    } else {
        vector<I> u(n);
        u[n - 1] = t[n - 1];
        for(I i = n - 2, d = 1; i >= 0; --i, ++d) {
            u[i] = u[i + 1] + min(d, t[i]);
            if(t[i] <= d) {
                d = 0;
            }
        }

        for(I i = 0; i < n; ++i) {
            cout << u[i] << ' ';
        } cout << '\n';

        cout << u[0] << '\n';
    }

    return 0;
}

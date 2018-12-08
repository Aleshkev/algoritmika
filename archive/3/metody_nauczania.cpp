#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n, k;
    cin >> n >> k;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());

    vector<I> v;

    I q = k;

    I p = pow(n, 3) / n;
    while(p > 0) {
        I part = q / p;
        v.push_back(part);
        cout << "q = " << q << ", p = " << p << ", part = " << part << '\n';
        q -= part * p;
        p /= n;
    }

    I c = 0;
    for(I i : v) {
        c += t[i];
    }
    cout << c << '\n';

    return 0;
}

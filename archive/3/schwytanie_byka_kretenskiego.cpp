#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef long double F;


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    F acc_v = 0.0, acc_s = 0.0, acc_t = 0.0;
    for(I i = 0; i < n; ++i) {
        F a, t;
        cin >> a >> t;

        acc_s += acc_v * t;

        acc_s += a * t * t / 2.0;
        acc_v += a * t;
    }
    cout << fixed << setprecision(2) << abs(acc_v) << ' ' << fixed << setprecision(2) << abs(acc_s) << '\n';

    return 0;
}

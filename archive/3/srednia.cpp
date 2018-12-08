#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef long double F;
const F inf = 1e18;

I n, k;
F t[100000];

bool is_avg_possible(F avg) {
    static F v[100000];
    v[0] = t[0] - avg;
    for(I i = 1; i < n; ++i) {
        v[i] = max(v[i - 1], (F)0.0) + t[i] - avg;
    }

    //cout << "is_avg_possible(" << avg << ")\n";
    //cout << " t = "; for(I i = 0; i < n; ++i) cout << setw(4) << t[i] << ' '; cout << '\n';
    //cout << " u = "; for(I i = 0; i < n; ++i) cout << setw(4) << u[i] << ' '; cout << '\n';
    //cout << " v = "; for(I i = 0; i < n; ++i) cout << setw(4) << v[i] << ' '; cout << '\n';

    F current_sum = accumulate(t, t + k, -avg * k);
    F max_sum = -inf;
    for(I i = 0; i <= n - k; ++i) {
        max_sum = max(max_sum, current_sum + v[i] - t[i] + avg);
        current_sum = current_sum + t[i + k] - t[i];
    }
    //cout << "max_sum = " << max_sum << " (" << (max_sum >= 0) << ")" << '\n';
    return max_sum >= 0;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    F lo = 1, hi = 1e6;
    while(hi - lo > 0.00001) {
        //cout << "checking " << lo << ":" << hi << '\n';
        F mid = (lo + hi) / 2;
        if(is_avg_possible(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(3) << hi << '\n';

    return 0;
}

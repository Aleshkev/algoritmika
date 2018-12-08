#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, k, p;
    cin >> n >> k;

    static I t[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    static I u[1000000];
    u[0] = t[0];
    I max_local = t[0];
    for(I i = 1; i < n; ++i) {
        max_local = max(max_local + t[i], t[i]);
        u[i] = max_local;
    }

    //cout << "t = "; for(I i = 0; i < n; ++i) cout << setw(2) << t[i] << ' '; cout << endl;
    //cout << "u = "; for(I i = 0; i < n; ++i) cout << setw(2) << u[i] << ' '; cout << endl;

    I current_sum = accumulate(t, t + k, 0);
    I max_sum = -inf;
    for(I i = 0; i <= n - k; ++i) {
        max_sum = max(max_sum, current_sum + u[i] - t[i]);

        current_sum = current_sum - t[i] + t[i + k];
    }

    cout << max_sum << '\n';

    return 0;
}

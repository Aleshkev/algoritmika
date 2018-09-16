#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main() {
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n;
    cin >> n;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<bool> is_used(n + 1);
    for(I i = 0; i < n; ++i) {
        is_used[t[i]] = true;
    }
    vector<I> unused;
    for(I i = 1; i <= n; ++i) {
        if(!is_used[i]) {
            unused.push_back(i);
        }
    }

    if(n <= 20) {
        I max_c = 0;
        for(I m = 1; m < (1 << n); ++m) {
            I c = __builtin_popcount(m);
            if(c <= max_c) {
                continue;
            }

            bool ok = true;
            I last = 0;
            for(I i = 0; i < n; ++i) {
                if(m & (1 << i)) {
                    if(t[i] > 0) {
                        if(t[i] <= last) {
                            ok = false;
                            break;
                        } else {
                            last = t[i];
                        }
                    } else {
                        auto it = upper_bound(unused.begin(), unused.end(), last);
                        if(it != unused.end()) {
                            last = *it;
                        } else {
                            ok = false;
                            break;
                        }
                    }
                    //if(m == 87) cout << last << ' ';
                }
            } //if(m == 87)cout << '\n';
            if(ok) {
                max_c = max(max_c, c);
                /*cout << m << " ok ";
                for(I i = 0; i < n; ++i) cout << bool((m & (1 << i)) > 0); cout << "\n";*/
            }
        }
        cout << max_c << '\n';
    } else {
        vector<I> dp(n + 1, inf);
        dp[0] = 0;

        for(I i = 0; i < n; ++i) {
            //for(I i = 1; i <= n; ++i) cout << setw(2) << i << ' '; cout << '\n';
            //for(I i = 1; i <= n; ++i) cout << setw(2) << dp[i] << ' '; cout << '\n';

            if(t[i] > 0) {
                I it = lower_bound(dp.begin(), dp.end(), t[i]) - dp.begin();
                if(dp[it] != t[i]) {
                    dp[it] = t[i];
                }
            } else {
                for(auto x = unused.rbegin(); x != unused.rend(); ++x) {
                    I it = lower_bound(dp.begin(), dp.end(), *x) - dp.begin();
                    if(dp[it] != t[i]) {
                        dp[it] = *x;
                    }
                }
            }
        }

        /*for(I i = 1; i <= n; ++i) {
            cout << i << ": " << dp[i] << '\n';
        } cout << '\n';*/

        I c = lower_bound(dp.begin(), dp.end(), inf) - dp.begin() - 1;
        cout << c << '\n';
    }

    return 0;
}

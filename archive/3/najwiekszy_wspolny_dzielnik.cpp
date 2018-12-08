#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

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

    {

        sort(t.begin(), t.end());

        I max_gcd = 1;

        for(I i = n - 1; t[i] > max_gcd; --i) {
            for(I j = i - 1; t[j] > max_gcd; --j) {
                max_gcd = max(max_gcd, __gcd(t[i], t[j]));
            }
        }
        cout << max_gcd << '\n';
    }

    {
        static I cnt[100000 + 1];
        I max_x = 0;
        for(I i = 0; i < n; ++i) {
            ++cnt[t[i]];
            max_x = max(max_x, t[i]);
        }

        I ans = 1;
        for(I i = 2; i <= max_x; ++i) {
            I k = 0;
            for(I j = i; j <= max_x; j += i) {
                k += cnt[j];
            }
            if(k > 1) {
                ans = max(ans, i);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef pair<I, I> II;
const II none = II(-1, -1);

I price_of(char c) {
    return (c == 'W' ? 1 : 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);

    I n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    //cout << s << '\n';

    vector<I> prices(n + 1);
    for(I i = 1; i <= n; ++i) {
        prices[i] = price_of(s[i - 1]);
    }

    vector<I> prices_prefix(n + 1);
    partial_sum(prices.begin(), prices.end(), prices_prefix.begin());

    /*for(I i = 0; i < m; ++i) {
        I k;
        cin >> k;

        bool any_ok = false;
        for(I i = 1; i <= n; ++i) {
            for(I j = i; j <= n; ++j) {
                I s = prices_prefix[j] - prices_prefix[i - 1];
                if(s == k) {
                    cout << i << ' ' << j << '\n';
                    any_ok = true;
                    break;
                }
            }
            if(any_ok) {
                break;
            }
        }

        if(!any_ok) {
            cout << "NIE\n";
        }
    }*/

    for(I i = 1; i <= m; ++i) {
        I k;
        cin >> k;

        bool any_ok = false;

        for(I i = k; i <= n; ++i) {
            I x = prices_prefix[i];
            I d = x - k;

            auto lo = lower_bound(prices_prefix.begin(), prices_prefix.end(), d) - prices_prefix.begin();
            if(0 <= lo && lo < n && prices_prefix[lo] == d) {
                cout << lo + 1 << ' ' << i << '\n';
                any_ok = true;
                break;
            }
        }

        if(!any_ok) {
            cout << "NIE\n";
        }
    }

    /*vector<II> answer(2 * n + 1, none);

    for(I i = 1; i <= n; ++i) {
        I x = prefixes[i];
        for(I j = 1; j <= 2 * n; ++j) {
            I y = j;
            if(x - y < 0) {
                break;
            }
            auto lo = lower_bound(prefixes.begin(), prefixes.end(), x - y) - prefixes.begin();
            auto hi = upper_bound(prefixes.begin(), prefixes.end(), x - y) - prefixes.begin();
            //cout << "searching, i = " << i << ", j = " << j << ", x = " << x << ", y = " << y << ", x - y = " << x - y << '\n';
            if(hi - lo > 0 && answer[j] == none) {
                answer[j].first = lo + 1;
                answer[j].second = i;
                //cout << j << ": " << lo << ":" << hi << '\n';
            }
        }
    }

    for(I i = 1; i <= n; ++i) {
        cout << i << ": " << answer[i].first << ' ' << answer[i].second << '\n';
    }

    for(I i = 0; i < m; ++i) {
        I k;
        cin >> k;
        if(answer[k] == none) {
            cout << "NIE\n";
        } else {
            cout << answer[k].first << ' ' << answer[k].second << '\n';
        }
    }*/

    return 0;
}

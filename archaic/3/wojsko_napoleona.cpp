#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef pair<I, I> II;

I n, k;
vector<II> heights;

bool is_possible(I x) {
    I sep_needed = 1;  // Final.

    I lim_a = heights[0].first - x, lim_b = heights[0].second + x;
    for(I i = 1; i < n; ++i) {
        I a = heights[i].first, b = heights[i].second;

        if(a > lim_b) {
            ++sep_needed;
            lim_a = a - x;
            lim_b = b + x;
        } else {
            lim_a = max(lim_a, a - x);
            lim_b = min(lim_b, b + x);
        }
    }

    return sep_needed <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    heights.resize(n);
    for(I i = 0; i < n; ++i) {
        cin >> heights[i].first >> heights[i].second;
    }
    sort(heights.begin(), heights.end());

    I lo = 0, hi = 1e9;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(is_possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << '\n';
}

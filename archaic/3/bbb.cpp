#include <bits/stdc++.h>

using namespace std;

typedef int I;
const I inf = 1e9;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, p, q, x, y;
    cin >> n >> p >> q >> x >> y;

    vector<I> t(n);
    string s;
    cin >> s;

    for(I i = 0; i < n; ++i) {
        t[i] = (s[i] == '+' ? 1 : -1);
    }

    /*I all_sum = accumulate(t.begin(), t.end(), 0);

    I min_c = inf;

    for(I shift = 0; shift < n; ++shift) {
        vector<I> sum(n);
        sum[0] = t[shift];
        for(I i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + t[(shift + i) % n];
        }
        //for(I i = 0; i < n; ++i) cout << setw(2) << sum[i] << ' '; cout << '\n';

        I pluses = max((-*min_element(sum.begin(), sum.end()) - p + 1) / 2, (I)0);
        I minuses = abs(q - (p + all_sum + 2 * pluses)) / 2;

        I c = (pluses + minuses) * x + ((n - shift) % n) * y;
        min_c = min(min_c, c);
        //cout << shift << ": " << pluses << " pluses, " << minuses << " minuses -> " << c << '\n';
    }*/

    vector<I> sum(n);
    partial_sum(t.begin(), t.end(), sum.begin());

    vector<I> min_from_left(n), min_from_right(n);
    auto lambda = [](I a, I b){return min(a, b); };
    partial_sum(sum.begin(), sum.end(), min_from_left.begin(), lambda);
    partial_sum(sum.rbegin(), sum.rend(), min_from_right.rbegin(), lambda);

    //for(I i = 0; i < n; ++i) cout << setw(2) << i << ' '; cout << '\n';
    //for(I i = 0; i < n; ++i) cout << setw(2) << (t[i] > 0 ? '+' : '-') << ' '; cout << '\n';
    //for(I i = 0; i < n; ++i) cout << setw(2) << sum[i] << ' '; cout << '\n';
    //for(I i = 0; i < n; ++i) cout << setw(2) << min_from_left[i] << ' '; cout << '\n';
    //for(I i = 0; i < n; ++i) cout << setw(2) << min_from_right[i] << ' '; cout << '\n';

    I total_sum = sum[n - 1];

    I min_c = inf;

    for(I sep = 0; sep < n; ++sep) {
        I min_to_right = min_from_right[sep];
        I one_to_left = (sep > 0 ? sum[sep - 1] : 0);
        I min_to_left = (sep > 0 ? min_from_left[sep - 1] : inf);

        I min_here = min(min_to_right - one_to_left,
                         min_to_left + total_sum - one_to_left);

        I pluses = max((-min_here - p + 1) / 2,
                       I(0));
        I additional_changes = abs(q - (p + total_sum + 2 * pluses)) / 2;

        I c = ((pluses + additional_changes) * x +
               ((n - sep) % n) * y);

        min_c = min(min_c, c);
    }

    cout << min_c << '\n';

    return 0;
}

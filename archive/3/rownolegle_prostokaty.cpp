#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n;
    cin >> n;

    vector<I> x(n), y(n);
    for(I i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<I> x_copy;
    x_copy.assign(x.begin(), x.end());
    sort(x_copy.begin(), x_copy.end());
    x_copy.erase(unique(x_copy.begin(), x_copy.end()), x_copy.end());

    for(I i = 0; i < n; ++i) {
        x[i] = lower_bound(x_copy.begin(), x_copy.end(), x[i]) - x_copy.begin();
    }

    vector<vector<I>> ys_at_x(x_copy.size());
    for(I i = 0; i < n; ++i) {
        ys_at_x[x[i]].push_back(y[i]);
    }
    for(auto &v : ys_at_x) {
        sort(v.begin(), v.end());
    }

    I c = 0;
    for(I a1 = 0; a1 < ys_at_x.size(); ++a1) {
        for(I b1 : ys_at_x[a1]) {
            for(I a2 = a1; a2 < ys_at_x.size(); ++a2) {
                for(I b2 : ys_at_x[a2]) {
                    if((b2 - b1) * (a2 - a1) <= 0) {
                        continue;
                    }
                    auto try_a1b2 = lower_bound(ys_at_x[a1].begin(), ys_at_x[a1].end(), b2);
                    auto try_a2b1 = lower_bound(ys_at_x[a2].begin(), ys_at_x[a2].end(), b1);
                    if(try_a1b2 != ys_at_x[a1].end() && *try_a1b2 == b2 &&
                       try_a2b1 != ys_at_x[a2].end() && *try_a2b1 == b1) {
                        //cout << "found " << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << '\n';
                        ++c;
                    }
                }
            }
        }
    }

    cout << c << '\n';

    return 0;
}

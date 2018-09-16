#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

I n, k;
vector<I> t;

bool possible(I x) {
    I groups = 1;
    I current_sum = 0;
    I group_len = 0;
    I margin = 0;
    for(I i = 0; i < n; ++i) {
        if(current_sum + t[i] > x) {
            if(group_len < 2) {
                return false;
            }
            margin +=
            group_len = 0;
            ++groups;
            current_sum = 0;
        }
        ++group_len;
        current_sum += t[i];
        //cout << ' ' << i << ": " << groups << ' ' << current_sum << " (t[i] was " << t[i] << ")\n";
    }
    return groups == k;
}

int main() {
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    t.resize(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    /*for(I i = 0; i < n; ++i) {
        cout << t[i] << ' ';
    } cout << '\n';*/


    /*for(I i = 1; i <= 20; ++i) {
        cout << i << ": " << possible(i) << endl;
    }*/

    I lo = 1, hi = inf;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << '\n';

    return 0;
}

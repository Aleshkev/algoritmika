#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e10;

I wrap(const vector<I> &lengths, I width) {
    I c = 0;
    I lines = 1;
    for(I i = 0; i < lengths.size(); ++i) {
        if(lengths[i] > width) {
            return inf;
        }
        if(c + lengths[i] > width) {
            ++lines;
            c = 0;
        }
        c += lengths[i];
    }
    return lines;
}
bool is_possible(const vector<I> &lengths, I k) {
    return wrap(lengths, k) <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n;
    cin >> n;

    vector<I> heights(n);
    for(I i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    I lo = 0, hi = 1e9 + 1;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(is_possible(heights, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << '\n';

    return 0;
}

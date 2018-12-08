#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int I;

void cin_diffs(I d, I n, I *t) {
    I last = 0;
    for(I i = 0; i < n; ++i) {
        I curr; cin >> curr;
        t[i] = curr - last;
        last = curr;
    }
    t[n] = d - last;
    sort(t, t + n + 1);
}

I num_gt(I *xdiffs, I *ydiffs, I n, I num) {
    I x = n;
    I c = 0;
    for(I y = 0; y <= n; ++y) {
        while(xdiffs[x] * ydiffs[y] > num) {
            --x;
        }
        c += n - x;
    }
    return c;
}

int main()
{
    cout.sync_with_stdio(false);
    I w, h, n, k; cin >> w >> h >> n >> k;

    static I xdiffs[200001], ydiffs[200001];
    cin_diffs(w, n, xdiffs);
    cin_diffs(h, n, ydiffs);

    I max_f = xdiffs[n] * ydiffs[n];

    I low = 0, hi = max_f;
    while (low < hi) {
        I mid = (low + hi) / 2;
        if (k - 1 >= num_gt(xdiffs, ydiffs, n, mid)) {
            hi = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << '\n';


    return 0;
}

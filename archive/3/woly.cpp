#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    I n;
    cin >> n;

    I max_x1 = -inf, max_y1 = -inf, min_x2 = inf, min_y2 = inf;
    for(I i = 0; i < n; ++i) {
        I x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        max_x1 = max(max_x1, x1);
        max_y1 = max(max_y1, y1);
        min_x2 = min(min_x2, x2);
        min_y2 = min(min_y2, y2);
    }

    if(max_x1 < min_x2 && max_y1 < min_y2) {
        cout << abs(max_x1 - min_x2) * abs(max_y1 - min_y2) << '\n';
    } else {
        cout << "0\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    set<I> xs, ys;

    I c = 0;
    for(I i = 0; i < n; ++i) {
        I x, y;
        cin >> x >> y;

        if(!xs.count(x) && !ys.count(y)) {
            xs.insert(x); ys.insert(y);
            ++c;
        }
    }

    cout << c << '\n';

    return 0;
}

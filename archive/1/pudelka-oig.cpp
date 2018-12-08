#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I n;
    cin >> n;

    I max_c = 1, c = 1, last = -1;
    for(I i = 0; i < n; ++i) {
        I e;
        cin >> e;
        if(e == last) {
            ++c;
        } else {
            max_c = max(max_c, c);
            c = 1;
        }
        last = e;
    }
    max_c = max(max_c, c);

    cout << max_c << '\n';

    return 0;
}

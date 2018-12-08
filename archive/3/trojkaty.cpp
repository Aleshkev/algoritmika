#include <bits/stdc++.h>

using namespace std;

typedef long long I;
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I x[3], y[3];
    for(I i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }

    I c = 0;
    for(I i = 0; i < 3; ++i) {
        I j = (i + 1) % 3;
        c += (x[j] - x[i]) * (y[j] + y[i]);
    }
    cout << (c > 0 ? "ZGODNIE" : "PRZECIWNIE") << '\n';



    return 0;
}

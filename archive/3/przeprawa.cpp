#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    I n, t;
    cin >> n >> t;

    static I u[100002];
    for(I i = 1; i <= n; ++i) {
        cin >> u[i];
    }

    static I v[100002];
    v[0] = 0;
    v[1] = u[1];
    v[2] = u[2];
    v[3] = u[3];
    for(I i = 4; i <= n + 1; ++i) {
        v[i] = u[i] + min(min(v[i - 1], v[i - 2]), v[i - 3]);
    }

    if(v[n + 1] <= t) {
        cout << "LIDL!!!\n";
        return 0;
    }

    I i = n;
    while(v[i] > t) {
        --i;
    }
    cout << i << '\n';

    return 0;
}

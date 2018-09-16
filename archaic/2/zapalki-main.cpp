#include <iostream>

using namespace std;

typedef int I;
const I inf = 1e7;

int main() {
    cout.sync_with_stdio(false);

    I n; cin >> n;

    static I t[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    static I u[1000000], v[1000000];
    u[0] = (t[0] == 0);
    for(I i = 1; i < n; ++i) {
        u[i] = u[i - 1] + (t[i] == 0);
    }
    v[n - 1] = (t[n - 1] == 1);
    for(I i = n - 1 - 1; i >= 0; --i) {
        v[i] = v[i + 1] + (t[i] == 1);
    }

    I x = inf;
    for(I i = 0; i <= n; ++i) {
        x = min(x, (i > 0 ? u[i - 1] : 0) + (i < n ? v[i] : 0));
    }
    cout << x << '\n';

    return 0;
}

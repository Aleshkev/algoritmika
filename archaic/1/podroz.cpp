#include <iostream>
#include <algorithm>

using namespace std;

typedef long long unsigned U;

int main()
{
    U n;
    cin >> n;

    U *t = new U[n];
    for(U i = 0; i < n; ++i) {
        cin >> t[i];
    }

    U m;
    cin >> m;
    for(U i = 0; i < m; ++i) {
        U min_pop, max_pop;
        cin >> min_pop >> max_pop;


        U d = distance(lower_bound(t, t + n, min_pop), upper_bound(t, t + n, max_pop - 1));
        cout << d << '\n';
    }

    return 0;
}

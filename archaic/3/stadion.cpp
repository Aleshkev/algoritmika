#include <bits/stdc++.h>

using namespace std;

typedef long int I;

struct Station {
    I z, d;
    I distance_from_start;
    Station() {};
    Station(I dist) : distance_from_start(dist) {};
};
bool operator<(Station a, Station b) {
    return a.distance_from_start < b.distance_from_start;
}


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    vector<I> z(n), d(n), u(n + 1);
    for(I i = 0; i < n; ++i) {
        cin >> z[i] >> d[i];
    }
    u[0] = 0;
    for(I i = 0; i < n; ++i) {
        u[i + 1] = u[i] + d[i];
    }
    if(u[n] == 0) u[n] = 1;

    //for(I i = 0; i <= n; ++i) cout << u[i] << ' '; cout << '\n';
    //for(I i = 0; i < n; ++i) cout << (u[i] + z[i]) % u[n] << ' '; cout << '\n';

    for(I i = 0; i < n; ++i) {
        cout << upper_bound(u.begin(), u.end(), (u[i] + z[i]) % u[n]) - u.begin() << '\n';
    }

    return 0;
}

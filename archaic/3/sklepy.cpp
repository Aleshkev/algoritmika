#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, k;
    cin >> n >> k;

    static I t[2000000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    static I u[2000000];
    partial_sum(t, t + n, u);

    multiset<I> s;
    for(I i = k - 2; i < n; ++i) {
        s.insert(u[i]);
    }

    for(I i = 0; i <= n - k; ++i) {
        s.erase(s.find(u[i + k - 2]));

        if(s.upper_bound(i > 0 ? u[i - 1] : 0) != s.end()) {
            cout << "TAK\n";
            return 0;
        }
    }

    cout << "NIE\n";

    return 0;
}

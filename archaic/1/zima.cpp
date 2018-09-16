#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    I n; cin >> n;

    static I t[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    static I u[1000000];
    fill(u, u + n, 1);

    I curr_max = 0;
    for(I i = 0; i < n; ++i) {
        curr_max = max(curr_max, u[i]);
        I j = i + t[i] + 1;
        if(j < n) u[j] = max(u[j], curr_max + 1);
    }

    cout << curr_max << endl;


    return 0;
}

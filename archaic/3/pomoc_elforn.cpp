#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n;
    cin >> n;

    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;

        cout << (x % 2 == 0 ? 'P' : 'N');
    }
    cout << '\n';

    return 0;
}

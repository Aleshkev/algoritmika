#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n;
    cin >> n;

    static I t[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    I c = 0;

    for(I i = 0; i < n; ++i) {
        I e;
        cin >> e;
        if(e < t[i]) ++c;
    }
    cout << c << '\n';

    return 0;
}

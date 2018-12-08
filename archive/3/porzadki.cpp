#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    static I t[200000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
        --t[i];
    }

    I chaos = 0;
    for(I i = 0; i < n; ++i) {
        if(t[i] != i) ++chaos;
    }

    I m;
    cin >> m;

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;

        if(t[a] == a) ++chaos;
        else if(t[a] == b) --chaos;
        if(t[b] == b) ++chaos;
        else if(t[b] == a) --chaos;

        swap(t[a], t[b]);

        cout << (chaos == 0 ? "TAK" : "NIE") << '\n';
    }

    return 0;
}

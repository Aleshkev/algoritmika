#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n; cin >> n; --n;

    static char t[1000001];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    t[n] = '-';

    for(I i = 0; i < n; ++i) {
        cout << '-';
        if(t[i] == '-' && t[i + 1] == '+') {
            cout << '(';
        } else if(t[i] == '+' && t[i + 1] == '-') {
            cout << ')';
        }
    }

    return 0;
}

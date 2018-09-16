#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n;
    cin >> n;

    string s;
    cin >> s;

    I badchar = n - 1;
    for(I i = 0; i < n - 2; ++i) {
        if(s[i] > s[i + 1]) {
            badchar = i;
            break;
        }
    }

    string z;
    for(I i = 0; i < n; ++i) {
        if(i != badchar) {
            z += s[i];
        }
    }
    cout << z << '\n';

    return 0;
}

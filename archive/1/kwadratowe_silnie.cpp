#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I n = 0;

    for(char c; ; ) {
        cin >> c;
        if(c == '!') break;
        n = n * 10 + (c - '0');
    }
    if(n == 1 || n == 3) cout << "TAK";
    else cout << "NIE";
    cout << endl;

    return 0;
}

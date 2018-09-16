#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I n;
    cin >> n;

    static I t[1000000];
    I err = 0;
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
        --t[i];
        if(t[i] != i) ++err;
    }

    if(err == 0) {
        cout << "Oj misie, misie!\n";
    } else {
        cout << err << '\n';
    }

    return 0;
}

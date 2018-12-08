#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I n, vol;
    cin >> n >> vol;

    static I t[50];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    const I d_vol = 30000;
    static I d[d_vol];
    d[t[0]] = 1;

    for(I i = 1; i < n; ++i) {
    for(I i = 0; i < 20; ++i) {
        cout << d[i] << ' ';
    } cout << '\n';
        for(I j = d_vol - 1; j >= 0; --j) {
            if(j + t[i] < d_vol) {
                d[j + t[i]] = max(d[j + t[i]], d[j] + 1);
            }
        }
    }
    for(I i = 0; i < 20; ++i) {
        cout << d[i] << ' ';
    } cout << '\n';

    cout << *max_element(d, d + vol + 1) << '\n';



    return 0;
}

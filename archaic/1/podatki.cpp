#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    I n; cin >> n;

    static I t[1000001];
    for(I i = 0; i < n; ++i) {
        I a; cin >> a;
        ++t[a];
    }

    I c = 0;
    I k = 1;
    for(I i = 1000000; i > 1; --i) {
        I lhalf = t[i] / 2, rhalf = t[i] - lhalf;
        if(rhalf == 0) continue;
        if(k == 1) {
            c += rhalf * 1;
            t[i - 1] += rhalf;
            c += lhalf * 2;
            t[i - 2] += lhalf;
            if(t[i] % 2 != 0) k = 2;
        } else {
            c += rhalf * 2;
            t[i - 2] += rhalf;
            c += lhalf * 1;
            t[i - 1] += lhalf;
            if(t[i] % 2 != 0) k = 1;
        }
    }
    if(k == 1 && t[1] > 0) ++c;

    cout << c << endl;

    return 0;
}

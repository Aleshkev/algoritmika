#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    const I sz = 92;
    static I t[sz] = {0, 1};
    for(I i = 2; i < sz; ++i) {
        t[i] = t[i - 1] + t[i - 2];
    }

    /*for(I i = 0; i < sz; ++i) {
        cout << t[i] << " ";
    }*/

    I p; cin >> p;

    for(I j = 0; j < p; ++j) {

        I r; cin >> r;

        I c = 0;

        while(r != 0) {
            I i = distance(t, upper_bound(t + 1, t + sz, r));
            I a = t[i - 1], b = t[i];
            //cout << a << " " << b << endl;
            if(abs(r - a) < abs(r - b)) {
                r = abs(r - a);
            } else {
                r = abs(r - b);
            }
            ++c;
            //cout << r << endl;
        }

        cout << c << '\n';
    }

    return 0;
}

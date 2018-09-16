#include <iostream>

using namespace std;

typedef long long unsigned U;

int main()
{
    U n, a;
    cin >> n >> a;

    U *t = new U[a + 1];
    fill_n(t, a + 1, 0);

    for(U i = 0; i < n; ++i) {
        U el;
        cin >> el;
        //cout << el % a << " " << el / a << '\n';
        ++t[el % a];
    }

    for(U i = 0; i <= a; ++i) {
        if(t[i] > 0) {
            cout << i << ' ' << t[i] << '\n';
        }
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long unsigned U;

int main()
{
    cout.sync_with_stdio(false);

    U n, j;  // Liczba kamieni, długość skoku
    cin >> n >> j;

    U *t = new U[n];
    for(U i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t, t + n);

    U last = 0;
    for(U i = 0; i < n; ++i) {
        if(t[i] > last + j) {
            break;
        }
        last = t[i];
    }

    cout << last + j << '\n';

    return 0;
}

#include <iostream>

using namespace std;

typedef size_t U;

// http://www.cauchy.pl/algorytmy-1/wyszukiwanie-binarne/pudelka/
int main()
{
    cout.sync_with_stdio(false);

    U n;
    cin >> n;

    U *arr = new U[n];
    for(U i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    U m;
    cin >> m;

    for(U i = 0; i < m; ++i) {
        U v;
        cin >> v;

        U index = distance(arr, lower_bound(arr, arr + n, v));

        if(arr[index] == v) {
            cout << index + 1 << '\n';
        } else {
            cout << "Kup pudelko!\n";
        }
    }

    return 0;
}

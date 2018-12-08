#include <iostream>
#include <set>

using namespace std;

typedef long long unsigned U;

int main()
{
    cout.sync_with_stdio(false);

    U n, k;  // Liczba elementow, liczba przez ktora musza byc podzielne
    cin >> n >> k;

    set<U> given;

    for(U i = 0; i < n; ++i) {
        U a;
        cin >> a;

        if(a % k == 0) {
            given.insert(a);
        }
    }

    U i = k;
    for(; ; i += k) {
        if(given.find(i) == given.end()) {
            break;
        }
    }
    cout << i << '\n';

    return 0;
}

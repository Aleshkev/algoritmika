//#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned U;

int main()
{
    //cout.sync_with_stdio(false);

    U n;
    //cin >> n;
    scanf("%u", &n);

    for(U i = 0; i < n; ++i) {
        U k;
        //cin >> k;
        scanf("%u", &k);

        U l = 2 * k - 1;
        if(__builtin_popcount(l) % 2 != 0) {
            --l;
        }
        //cout << --l << '\n';
        printf("%u\n", l);
    }


    return 0;
}

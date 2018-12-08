//#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long unsigned U;

// "llu" powinno dzialac, ale tego nie robi - na Windowsie zmien na "I64u"
#define PU "llu"

int main() {
    //cout.sync_with_stdio(false);

    U n;
    //cin >> n;
    scanf("%"PU, &n);

    //printf("%018"PU, (U)90895636199811092);

    const U x = 1e18;

    U c1 = 0, c2 = 0;  // c1 * x + c2 -> wynik
    for(U i = 1; i <= n; ++i) {
        U a;
        //cin >> a;
        scanf("%"PU, &a);

        U increment = (n - i + 1) * i * a;

        c2 += increment % x;

        while(c2 > x) {
            ++c1;
            c2 -= x;
        }


        c1 += increment / x;
    }

    if(c1 > 0) {
        printf("%"PU, c1);
        printf("%018"PU"\n", c2);
    } else {
        printf("%"PU"\n", c2);
    }
}

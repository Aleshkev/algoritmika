//#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long unsigned U;
typedef long long int I;

#define PU "I64u"

int main()
{
    U n, p;
    scanf("%"PU" %"PU, &n, &p);
    //cin >> n >> p;

    U *t = new U[p];
    fill_n(t, p, 0);

    for(U i = 0; i < n; ++i) {
        U a;
        //cin >> a;
        scanf("%"PU, &a);
        a %= p;
        ++t[a];
    }

    U c = 0;
    for(U i = 0; i < p; ++i) {
        if(t[i] == 1) {
            ++c;
        }
    }

    //cout << c << "\n";
    printf("%"PU, c);

    return 0;
}

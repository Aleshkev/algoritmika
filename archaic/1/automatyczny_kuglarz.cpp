//#include <iostream>
#include <cstdio>

using namespace std;

typedef long long unsigned U;
#define PU "llu"

int main()
{
    //cout.sync_with_stdio(false);

    U n;  // Liczba losowań
    scanf("%"PU, &n);
    //cin >> n;

    U current = 0;

    for(U i = 0; i < n; ++i) {
        char t;  // Znak
        U l;  // Liczba zamian
        //cin >> t >> l;
        scanf(" %c %"PU, &t, &l);
        l %= 2;

        if(l) {
            U a, b;

            if(t == 'A')      a = 1, b = 2;
            else if(t == 'B') a = 1, b = 3;
            else if(t == 'C') a = 1, b = 4;
            else if(t == 'D') a = 1, b = 5;
            else if(t == 'E') a = 2, b = 3;
            else if(t == 'F') a = 2, b = 4;
            else if(t == 'G') a = 2, b = 5;
            else if(t == 'H') a = 3, b = 4;
            else if(t == 'I') a = 3, b = 5;
            else if(t == 'J') a = 4, b = 5;

            --a, --b;

            if(current == a) current = b;
            else if(current == b) current = a;
        }
    }

    //cout << current + 1 << endl;
    printf("%"PU, current + 1);

    return 0;
}

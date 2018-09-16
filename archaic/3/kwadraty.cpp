#include <bits/stdc++.h>

using namespace std;

typedef int I;
const I inf = 100000;

int main()
{

    for(;;) {
        I a, b;
        scanf("%i %i", &a, &b);

        if(a == 0 && b == 0) {
            break;
        }

        I last = inf;
        for(;;) {
            //cout << " " << a << ' ' << b << endl;
            if(a < b) {
                swap(a, b);
            }

            if(b >= last) {
                break;
            }
            last = b;
            a -= b;
        }

        printf("%s\n", (a == b ? "TAK" : "NIE"));
    }

    return 0;
}

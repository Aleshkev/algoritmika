#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    static I t[1001];

    for(;;) {
        I n;
        for(n = 0; ; ++n) {
            scanf("%i", &t[n]);
            if(t[n] == 0) break;
        }

        if(n == 0) break;

        sort(t, t + n);

        const bool can = (t[0] + t[1] > t[n - 1]);
        printf("%s\n", (can ? "TAK" : "NIE"));
    }

    return 0;
}

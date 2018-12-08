#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n;
    scanf("%i", &n);

    I t[100];
    for(I i = 0; i < n; ++i) {
        scanf("%i", &t[i]);
    }

    I x = t[0];
    for(I i = 1; i < n; ++i) {
        x ^= t[i];
    }

    ///cout << x << endl;



    printf("%s\n",  (x != 0 ? "Andrzej" : "Blazej"));


    return 0;
}

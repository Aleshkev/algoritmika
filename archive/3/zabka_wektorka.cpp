#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I n;
    scanf("%li", &n);

    I sx = 0, sy = 0;
    for(I i = 0; i < n + 1; ++i) {
        I dx, dy;
        scanf("%li %li", &dx, &dy);
        sx += dx; sy += dy;
    }

    printf("%li %li\n", sx, sy);


    return 0;
}

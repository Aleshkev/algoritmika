#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I n;
    scanf("%li", &n);

    static I t[100][101];

    for(I i = 0; i < n / 2 + 1; ++i) {
        for(I x = i; x < n - i; ++x) {
            t[i][x] = t[n - i - 1][x] = i + 1;
        }
        for(I y = i; y < n - i; ++y) {
            t[y][i] = t[y][n - i - 1] = i + 1;
        }
    }

    for(I y = 0; y < n; ++y) {
        for(I x = 0; x < n; ++x) {
            printf("%li ", t[y][x]);
        }
        printf("\n");
    }

    return 0;
}

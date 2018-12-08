#include <iostream>
//#include <cstdio>

using namespace std;

typedef long long unsigned U;

int main()
{
    //cout.sync_with_stdio(false);

    U dist;
    cin >> dist;
    //scanf("%I64u", &dist);

    U c = 0;

    U step = 1;
    U rest = dist;
    for(; rest >= step; step *= 2) {
        rest -= step;
        ++c;
    }
    for(; rest > 0; step /= 2) {
        while(rest >= step) {
            rest -= step;
            ++c;
        }
    }

    cout << c << '\n';
    //printf("%I64u\n", c);

    return 0;
}

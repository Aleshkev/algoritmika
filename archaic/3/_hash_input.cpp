#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long unsigned h = 0;
    for(;;) {
        int c = getchar();
        if(c == EOF) break;
        h = ((h << 8) + c) % 1000000009;
    }
    cout << h << '\n';
    return 0;
}

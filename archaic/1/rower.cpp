#include <iostream>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    I n, k; cin >> n >> k;

    I c = -1;
    for(I i = 0; i < n; ++i) {
        I a; cin >> a;
        if(a <= k && a > c) {
            c = a;
        }
    }

    cout << c << '\n';

    return 0;
}

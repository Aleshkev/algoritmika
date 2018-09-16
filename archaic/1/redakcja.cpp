#include <iostream>

using namespace std;

typedef int I;

int main()
{
    I n; cin >> n;

    static I t[200000];
    for(I i = 0; i < n; ++i) {
        I a; cin >> a; --a;
        t[a] = i;
    }

    I lo = t[0], hi = t[0];
    I c = 1;
    for(I i = 1; i < n; ++i) {
        I j = t[i];
        if(j < lo) {
            lo = j;
        } else if(j > hi) {
            hi = j;
        }

        if(hi - lo + 1 == i + 1) {
            ++c;
        }
    }

    cout << c << '\n';

    return 0;
}

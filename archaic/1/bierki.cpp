#include <iostream>

using namespace std;

typedef int I;

int main()
{
    I n; cin >> n;

    static I t[501];
    for(I i = 0; i < n; ++i) {
        I l; cin >> l;
        ++t[l];
    }

    I max_c = 0;
    for(I i = 1; i < 500 - 2; ++i) {
        for(I j = i + 1; j < 500 - 1; ++j) {
            for(I k = j + 1; k < 500; ++k) {
                if()
            }
        }
    }

    return 0;
}

#include <iostream>

using namespace std;

typedef long long unsigned U;
typedef double F;

int main()
{
    cout.sync_with_stdio(false);

    U p;
    cin >> p;

    U sl = 0, sm = 1e4;
    for(U i = 1; i <= p; ++i) {
        if(p % i == 0 && 1000 % i == 0) {
            sl = p / i;
            sm = 1000 / i;

            if(sl == 1) {
                break;
            }
        }
    }
    cout << sl << '/' << sm << '\n';

    return 0;
}

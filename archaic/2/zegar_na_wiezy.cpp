#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long int I;
typedef double F;

int main()
{
    I h, m; cin >> h >> m;
    h %= 12;

    I t = 60*h - 12*m;
    if(t < 0) t = -t;

    cout << t / 11;
    if(t % 11 != 0) {
        cout << ' ' << t % 11 << "/11";
    }
    cout << '\n';

    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

typedef long long int I;
typedef double F;

int main()
{
    cout.sync_with_stdio(false);

    I n;
    cin >> n;

    I c = 0;
    for(I i = 0; i < n; ++i) {
        I d;
        cin >> d;

        d -= 10;
        if(d <= 0)
            continue;

        c += ceil(d / F(10.0));
    }

    cout << c << endl;

    return 0;
}

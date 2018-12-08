#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n; cin >> n;

    I c = 0;

    I k = 1;
    while(n >= k - 1) k *= 2, ++c;
    k /= 2, --c;

    n -= (k - 1);

    for(; k > 0; k /= 2) {
        c += n / k;
        n %= k;
    }

    cout << c << endl;

    return 0;
}

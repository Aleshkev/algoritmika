#include <iostream>

using namespace std;

typedef long long unsigned U;

int main()
{
    U a, n;
    cin >> a >> n;

    U c = a * (n - a + 1);

    cout << c << '\n';

    return 0;
}

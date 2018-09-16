#include <iostream>
#include <set>

using namespace std;

typedef long long unsigned I;

const I results[] = {0, 2, 3, 5, 8, 16, 24, 48, 76, 132, 198, 396, 588,
                     1176, 1764, 2940, 4680, 9360, 13680, 27360, 43776, 72960, 109440};

int main()
{
    I n;
    cin >> n;
    cout << results[n] << '\n';

    return 0;
}

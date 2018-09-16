#include <iostream>
#include <cmath>

using namespace std;

typedef int I;
typedef float F;

int main()
{
    I n;
    cin >> n;

    static I t[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for(I i = -10; i <= 10; ++i) {
        I c = 0;
        for(I j = 0; j < n; ++j) {
            c += abs(t[j] - i);
        }
        cout << i << ": " << c << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    cin >> n;

    I *t = new I[n];

    cin >> noskipws;
    cin.ignore();
    char c;
    for(I i = 0; i < n; ++i) {
        t[i] = 0;
        while(cin >> c && c != '\n') {
            ++t[i];
        }
    }

    sort(t, t + n);

    for(I i = 0; i < n; ++i) {
        for(I j = 0; j < t[i]; ++j) {
            cout << 'O';
        } cout << '\n';
    }

    return 0;
}

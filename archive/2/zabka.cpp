#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    cin.sync_with_stdio(false);

    I n; cin >> n;

    for(I i = 0; i < n; ++i) {
        I a, b; cin >> a >> b;
        I lim_begin = a, lim_end = a;
        while(lim_end < b) {
            lim_begin = 2 * lim_begin;
            lim_end = 2 * lim_end + 1;
        }
        bool achievable = (lim_begin <= b && b <= lim_end);
        cout << (achievable ? "TAK" : "NIE") << '\n';
    }

    return 0;
}

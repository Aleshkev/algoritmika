#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    I n;
    cin >> n;

    static I t[256];
    I c = 0;
    for(I i = 0; i < n; ++i) {
        char ch;
        cin >> ch;

        if(islower(ch) ? t[toupper(ch)] : t[tolower(ch)]) {
            ++c;
        }

        ++t[(I)ch];
    }

    cout << c << endl;

    return 0;
}

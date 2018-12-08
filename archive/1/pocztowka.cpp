#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n, h;
    cin >> n >> h;

    bool *t = new bool[n];
    for(I i = 0; i < n; ++i) {
        I a;
        cin >> a;
        t[i] = (a >= h);
    }

    I c = 0;

    I b = 0, e = 0;
    I g = 0;
    if(t[0]) {
        ++g;
    }
    while(b < n) {
        while(g == 0) {
            ++e;
            if(e == n) {
                break;
            }
            if(t[e]) {
                ++g;
            }
        }
        if(e == n) {
            break;
        }

        //cout << b << " " << e << " (" << g << ") " << endl;

        c += (n - e);

        if(t[b]) {
            --g;
        }
        ++b;
    }

    cout << c << '\n';

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    cin >> n;

    I *t = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
        --t[i];
    }

    I max_a = *max_element(t, t + n);
    I *u = new I[max_a];
    fill(u, u + max_a, -1);
    for(I i = 0; i < n; ++i) {
        u[t[i]] = i;
    }

    for(I i = 0; i < n; ++i) {
        cout << t[i] << " ";
    } cout << endl;

    for(I i = 0; i < max_a; ++i) {
        if(u[i] != -1) {
            cout << i << ": " << u[i] << endl;
        }
    }

    I c = 0;

    I b = 0, e = 0;
    while(b < n) {
        do {
            ++b;
            e = max(e, u[t[b]]);
        } while(b < e)
        cout << "found " << b << ":" << e << endl;

        ++c;
    }

    cout << c << endl;

    return 0;
}

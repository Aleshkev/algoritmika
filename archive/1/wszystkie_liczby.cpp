#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    I *t = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
        --t[i];
    }

    I *u = new I[m];
    fill(u, u + m, 0);

    I *v = new I[n];
    fill(v, v + n, -1);

    I first = 0, last = 0;
    ++u[t[0]];
    while(first < n) {
        for(I i = 0; i < m; ++i) {
            while(last < n && u[i] == 0) {
                ++last;
                if(last < n) {
                    ++u[t[last]];
                }
            }
        }

        if(last < n) {
            v[first] = last;
        } else {
            break;
        }

        --u[t[first]];

        ++first;
    }

    I o;
    cin >> o;
    for(I i = 0; i < o; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;

        if(v[a] != -1 && b >= v[a]) {
            cout << "OUI\n";
        } else {
            cout << "NON\n";
        }
    }

    return 0;
}

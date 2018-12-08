#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef unsigned U;
typedef int I;
typedef float F;

int main()
{
    U n;
    cin >> n;

    char *s = new char[n + 1];
    cin >> s;

    vector<U> t;

    U l = 0;
    for(U i = 0; i < n; ++i) {
        if(s[i] == 'W') {
            if(l > 0) {
                t.push_back(l);
                l = 0;
            }
        } else {
            ++l;
        }
    }
    if(l > 0) {
        t.push_back(l);
    }

    U c = 0;
    for(U i = 0; i < t.size(); ++i) {
        c += ceil(t[i] / 3.0);
    }

    cout << c << '\n';

    return 0;
}

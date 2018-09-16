#include <iostream>

using namespace std;

typedef long unsigned U;
typedef long int I;

// 6 8 4 2 5 7 8
int main()
{
    cout.sync_with_stdio(false);

    U n;
    cin >> n;

    I *t = new I[n];
    U *sz = new U[n];

    t[0] = -1;
    cin >> sz[0];
    cout << t[0] << '\n';

    for(U i = 1; i < n; ++i) {
        cin >> sz[i];

        t[i] = -1;
        for(I j = i - 1; ; ) {
            if(t[j] == -1 && sz[j] <= sz[i]) {
                t[i] = -1;
                break;
            } else if(sz[j] > sz[i]) {
                t[i] = j;
                break;
            } else {
                j = t[j];
            }
        }

        cout << (t[i] == -1 ? -1 : t[i] + 1) << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

typedef long long unsigned U;

int main()
{
    U n;
    cin >> n;

    U *t = new U[n + 1];
    t[0] = 0;
    for(U i = 1; i <= n; ++i) {
        cin >> t[i];
        t[i] += t[i - 1];
    }

    //for(U i = 0; i < n; ++i) {
    //    cout << t[i] << " ";
    //}cout << endl;

    U m;
    cin >> m;

    for(U i = 0; i < m; ++i) {
        U a, b;
        cin >> a >> b;
        --a;
        cout << t[b] - t[a] << '\n';
        //cout << t[b] << " - " << t[a] << " = " << t[b] - t[a] << '\n';
    }

    return 0;
}

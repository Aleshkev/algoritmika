#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n;
    cin >> n;
    const I LIM = 1e6 + 5;

    I c = 0;

    I *t = new I[LIM];
    for(I i = 0; i < LIM; ++i) {
        t[i] = 0;
        ++c;
    }
    for(I i = 0; i < n; ++i) {
        I a;
        cin >> a;
        ++t[a];
    }

    I *u = new I[LIM];
    u[1] = n;
    for(I i = 2; i < LIM; ++i) {
        for(I j = i; j < LIM; j += i) {
            u[i] += t[j];
            ++c;
        }
    }

    /*for(I i = 0; i < 10; ++i) {
        cout << t[i] << " ";
    } cout << endl;

    for(I i = 0; i < 10; ++i) {
        cout << u[i] << " ";
    } cout << endl;

    cout << c << endl;*/

    I m;
    cin >> m;

    for(I i = 0; i < m; ++i) {
        I a;
        cin >> a;
        cout << u[a] << '\n';
    }

    return 0;
}

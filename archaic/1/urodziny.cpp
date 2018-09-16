#include <iostream>
#include <vector>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    cin >> n;

    vector<I> t;
    for(I i = 0; i < n; ++i) {
        I a, b;
        cin >> a >> b;
        if(a == b) {
            continue;
        }
        I diff = a > b ? a - b : b - a;
        t.push_back(diff);
    }

    const I U_SIZE = 500000;
    static bool u[U_SIZE + 1];
    fill(u, u + U_SIZE + 1, false);
    u[0] = true;

    for(I i = 0; i < t.size(); ++i) {
        for(I j = U_SIZE; j >= 0; --j) {
            if(!u[j]) {
                continue;
            }

            if(t[i] + j > U_SIZE) {
                continue;
            }

            u[t[i] + j] = true;
        }
    }

    for(I i = 0; i < t.size(); ++i) {
        cout << t[i] << " ";
    } cout << endl;

    for(I i = 1; i <= 100; ++i) {
        cout << u[i] << " ";
    }
    cout << endl;


    return 0;
}

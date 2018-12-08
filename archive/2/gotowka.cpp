#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    cin >> n;

    I *t = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    I *scores = new I[1 << n];
    scores[0] = 1;

    for(I i = 1; i < (1 << n); ++i) {
        I c = 0, perm = 0;
        for(I j = 0; j < n; ++j) {
            if((i & (1 << j)) > 0) {
                c += t[j];
                perm += scores[i - (1 << j)];
            }
        }
        if(c >= 0) {
            scores[i] = perm % I(1e9 + 7);
        } else {
            scores[i] = 0;
        }
    }

    cout << scores[(1 << n) - 1] << endl;

    return 0;
}

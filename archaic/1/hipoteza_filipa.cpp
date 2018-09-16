#include <iostream>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    const I primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31, 37};

    I m; cin >> m;

    for(I i = 0; i < m; ++i) {
        I n; cin >> n;

        I p;
        for(I i = 0; ; ++i) {
            if(n % primes[i] != 0) {
                p = primes[i];
                break;
            }
        }

        //cout << "p=" << p << endl;

        for(I i = 2; ; ++i) {
            if((n * i + 1) % p == 0) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    I n, k;
    cin >> n >> k;

    vector<I> passengers(n);

    for(I i = 0; i < n; ++i) {
        for(I j = i + 1; j < n; ++j) {
            I x;
            cin >> x;
            for(I z = i; z < j; ++z) {
                passengers[z] += x;
            }
        }
    }

    for(I i : passengers) cout << i << ' '; cout << '\n';

    cout << "read";


    return 0;
}

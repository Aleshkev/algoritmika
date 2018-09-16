#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    ios_base::sync_with_stdio(false);

    I n;
    cin >> n;

    const I max_n = 1e5;
    const I max_l = 1e7;

    static I t[max_n];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t, t + n);

    I c = 0;
    for(I i = 0; i < n; ++i) {
        for(I j = i + 1; j < n; ++j) {
            if(__gcd(t[i], t[j]) == 1) {
                ++c;
            }
        }
    }
    cout << c << '\n';

    return 0;
}

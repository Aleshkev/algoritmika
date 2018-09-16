#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I q;
    cin >> q;
    for(I qi = 0; qi < q; ++qi) {
        I n;
        cin >> n;

        vector<I> t(n);
        for(I i = 0; i < n; ++i) {
            cin >> t[i];
        }

        vector<I> layers(n + 2, inf);
        layers[0] = -inf;
        layers[1] = t[0];

        for(I i = 1; i < n; ++i) {
            I k = lower_bound(layers.begin(), layers.end(), t[i]) - layers.begin() - 1;
            layers[k + 1] = min(layers[k + 1], t[i]);
        }


        /*for(I i = 1; i <= n; ++i) {
            cout << layers[i] << ' ';
        } cout << '\n';*/

        cout << lower_bound(layers.begin(), layers.end(), inf) - layers.begin() - 1 << '\n';

    }
    return 0;
}

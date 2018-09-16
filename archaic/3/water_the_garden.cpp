#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I q;
    cin >> q;

    for(I qi = 0; qi < q; ++qi) {
        I n, k;
        cin >> n >> k;

        vector<I> t(k);
        for(I i = 0; i < k; ++i) {
            cin >> t[i];
        }

        I max_c = max(t[0] - 1, n - t[k - 1]);
        for(I i = 0; i < k- 1; ++i) {
            max_c = max(max_c, (t[i + 1] - t[i]) / 2);
        }
        cout << max_c + 1 << '\n';
    }

    return 0;
}

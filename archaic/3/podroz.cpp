#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n;
    cin >> n;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());

    I m;
    cin >> m;

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        cout << upper_bound(t.begin(), t.end(), b - 1) - lower_bound(t.begin(), t.end(), a) << '\n';
    }

    return 0;
}

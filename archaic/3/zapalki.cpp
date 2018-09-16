#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    I n;
    cin >> n;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<I> u(n), v(n);
    u[0] = 0;
    for(I i = 1; i < n; ++i) {
        u[i] = (t[i] >= t[i - 1] ? u[i - 1] : i);
    }
    v[n - 1] = n - 1;
    for(I i = n - 1 - 1; i >= 0; --i) {
        v[i] = (t[i] >= t[i + 1] ? v[i + 1] : i);
    }

    I max_c = 0;
    for(I i = 0; i < n; ++i) {
        max_c = max(max_c, v[i] - u[i] + 1);
    }
    cout << max_c << '\n';

    return 0;
}

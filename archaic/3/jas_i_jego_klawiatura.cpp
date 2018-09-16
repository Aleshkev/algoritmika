#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I lim = 123456789;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n, m;
    cin >> n >> m;

    bool compatible[26][26];
    for(I i = 0; i < 26; ++i) {
        fill(compatible[i], compatible[i] + 26, true);
    }
    for(I i = 0; i < m; ++i) {
        char a, b;
        cin >> a >> b;
        compatible[a - 'a'][b - 'a'] = false;
    }

    I t[26], u[26];
    fill(t, t + 26, 1);

    for(I i = 2; i <= n; ++i) {
        for(I j = 0; j < 26; ++j) {
            u[j] = 0;
            for(I k = 0; k < 26; ++k) {
                if(compatible[k][j]) {
                    u[j] += t[k];
                    u[j] %= lim;
                }
            }
        }
        //for(I i = 0; i < 26; ++i) cout << setw(4) << t[i] << ' '; cout << '\n';
        //for(I i = 0; i < 26; ++i) cout << setw(4) << u[i] << ' '; cout << '\n';
        swap(t, u);
    }
    cout << accumulate(t, t + 26, 0) % lim << '\n';

    return 0;
}

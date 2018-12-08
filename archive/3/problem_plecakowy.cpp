#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
typedef pair<I, I> II;

#define max(A, B) (A > B ? A : B)

inline I gp2(I x) {
    return sizeof(I) * 8 - __builtin_clz(x) - 1;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n, m;
    cin >> n >> m;

    static II wv[7000];
    for(I i = 0; i < n; ++i) {
        cin >> wv[i].first >> wv[i].second;
    }
    sort(wv, wv + n);

    static I w[7000], v[7000];
    for(I i = 0; i < n; ++i) {
        tie(w[i], v[i]) = wv[i];
    }

    /*for(I i = 0; i < n; ++i) cout << setw(2) << i << ' '; cout << '\n';
    for(I i = 0; i < n; ++i) cout << setw(2) << w[i] << ' '; cout << '\n';
    for(I i = 0; i < n; ++i) cout << setw(2) << v[i] << ' '; cout << '\n';*/

    static I qv[13][7000];
    for(I i = 0; i < n; ++i) {
        qv[0][i] = v[i];
    }
    for(I j = 1; j < 13; ++j) {
        for(I i = 0; i < n - (1 << j) + 1; ++i) {
            qv[j][i] = max(qv[j - 1][i], qv[j - 1][i + (1 << j >> 1)]);
        }
    }
    /*for(I j = 0; j < 15; ++j) {
        for(I i = 0; i < n; ++i) {
            cout << qw[j][i] << ' ';
        } cout << '\n';
    }*/

    I c = 0;

    for(I z1 = 0; z1 < n; ++z1) {
        if(w[z1] > m) {
            break;
        }
        c = max(c, v[z1]);
    }
    for(I z1 = 0; z1 < n - 1; ++z1) {
        for(I z2 = z1 + 1; z2 < n; ++z2) {
            if(w[z1] + w[z2] > m) {
                break;
            }
            c = max(c, v[z1] + v[z2]);
        }
    }

    for(I z1 = 0; z1 < n - 2; ++z1) {
        for(I z2 = z1 + 1; z2 < n - 1; ++z2) {

            I i = upper_bound(w + z2 + 1, w + n, m - w[z1] - w[z2]) - w - 1;
            if(i <= z2) continue;

            I a = z2 + 1, b = i;
            I r = gp2(b - a + 1);
            I v_z3 = max(qv[r][a], qv[r][b - (1 << r) + 1]);

            //cout << z1 << ", " << z2 << ": " << "bound = " << a << ":" << b << ", c_z2 = " << c_z2 << " (r = " << (1 << r) << ")" << endl;

            c = max(c, v[z1] + v[z2] + v_z3);
        }
    }
    cout << c << '\n';

    return 0;
}

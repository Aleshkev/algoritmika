#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I q;
    cin >> q;

    for(I qi = 0; qi < q; ++qi) {
        I n;
        cin >> n;

        const I max_a = 3000;
        vector<I> d(max_a), nd(max_a);

        for(I i = 0; i < n; ++i) {
            I x;
            cin >> x;
            ++nd[x];
        }

        bool ok = true;
        for(I i = 0; i < max_a - 1; ++i) {
            if((d[i] + nd[i]) % 2 != 0) {
                if(d[i] > 0) {
                    --d[i];
                } else {
                    ok = false;
                    break;
                }
            }
            d[i + 1] += (d[i] + nd[i]) / 2;
        }
        cout << (ok ? "TAK" : "NIE") << '\n';
    }


    return 0;
}

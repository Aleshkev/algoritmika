#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;

int main()
{
    ios_base::sync_with_stdio(false);

    I n;
    cin >> n;

    const I lim = 1e6;
    vector<I> nwithgrade(lim + 1);
    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;
        ++nwithgrade[x];
    }

    vector<I> prefixnwithgrade(lim + 1);
    partial_sum(nwithgrade.begin(), nwithgrade.end(), prefixnwithgrade.begin());

    vector<I> rprefixweightgrade(lim + 1 + 1);
    rprefixweightgrade[lim + 1] = 0;
    for(I i = lim; i >= 0; --i) {
        rprefixweightgrade[i] = rprefixweightgrade[i + 1] + i * nwithgrade[i];
    }

    I sep = 0;
    for(;;) {
        I avg = (prefixnwithgrade[sep] * sep + rprefixweightgrade[sep + 1]) / n;
        if(sep == avg) {
            break;
        }
        sep = avg;
    }

    cout << fixed << setprecision(3) << F(prefixnwithgrade[sep] * sep + rprefixweightgrade[sep + 1]) / F(n) << '\n';

    return 0;
}

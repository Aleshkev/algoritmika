#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    ios_base::sync_with_stdio(false);

    I x, d;
    cin >> x >> d;

    vector<I> r;

    I c = 1;
    for(I i = 40; i >= 1; --i) {
        I sub = ((I)1 << i) - 1;
        while(x >= sub) {
            //cout << "add " << i << " for " << sub << " (x -> " << x - sub << ")\n";
            x -= sub;
            for(I j = 0; j < i; ++j) {
                r.push_back(c);
            }
            c += d;
        }
    }

    cout << r.size() << '\n';
    for(I i : r) cout << i << ' '; cout << '\n';

    return 0;
}

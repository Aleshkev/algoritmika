#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;
const I inf = 1e18;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n, k, q;
    cin >> n >> k >> q;

    map<I, I> u;
    u[-1] = 0;

    for(I i = 0; i < n; ++i) {
        I a, b, c;
        cin >> a >> b >> c;
        u[a] += c;
        u[b + 1] -= c;
    }

    map<I, I> t;
    I x = 0;
    for(II p : u) {
        x += p.second;
        t[p.first] = x;
        //cout << p.first << ": " << x << '\n';
    }

    for(I i = 0; i < q; ++i) {
        I x;
        cin >> x;
        cout << prev(t.upper_bound(x))->second << '\n';
    }

    return 0;
}

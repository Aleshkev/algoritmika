#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

typedef long long unsigned I;

I qpow(I x, I n) {
    if(n == 0) return 0;
    else if(n == 1) return x;

    I frac_x = qpow(x, n / 2);
    return frac_x * frac_x * (n % 2 == 0 ? 1 : x);
}

int main()
{
    cout.sync_with_stdio(false);

    I x, y, k;
    cin >> x >> y >> k;

    I c1 = 1, c2 = 0;
    for(I i = 0; i < x * y; ++i) {
        c1 *= (k + 1);
    }

    vector<I> v;

    v.push_back(r % 60);
    r /=  60;
    v.push_back(r % 60);;
    r /= 60;
    v.push_back(r % 24);
    r /= 24;
    v.push_back(r % 356);
    r /= 356;

    reverse(v.begin(), v.end());

    for(vector<I>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << ' ';
    } cout << '\n';



    return 0;
}

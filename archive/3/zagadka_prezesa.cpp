#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);

    vector<I> in(10);
    for(I i = 0; i < 10; ++i) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());

    I ab = in[0], ac = in[1];
    I de = in[9], ce = in[8];

    I abcde = accumulate(in.begin(), in.end(), 0) / 4;
    I cde = abcde - ab;
    I c = cde - de, d = cde - ce, e = cde - c - d;
    I abc = abcde - de;
    I b = abc - ac, a = abc - b - c;

    cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n';

    return 0;
}

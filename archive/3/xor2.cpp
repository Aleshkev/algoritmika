#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned int I;

I xor_up_to(I n) {
    switch(n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
}

I rec(I m, I n) {
    if(n - m == 1) {
        return m ^ n;
    } else {
        I pivot = (m + n) / 2;
        if(pivot + 1 == n) {
            return rec(m, pivot) ^ n;
        } else {
            return rec(m, pivot) ^ rec(pivot + 1, n);
        }
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    I n;
    cin >> n;

    for(I i = 0; i < n; ++i) {
        I a, b;
        cin >> a >> b;
        //cout << (xor_up_to(a - 1) ^ xor_up_to(b)) << '\n';
        cout << rec(a, b) << '\n';
    }

    return 0;
}
